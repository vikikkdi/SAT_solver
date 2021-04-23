/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                              reLOC 0.21-robik                              */
/*                                                                            */
/*                      (C) Copyright 2019 Pavel Surynek                      */
/*                http://www.surynek.com | <pavel@surynek.com>                */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* gridgen_main.cpp / 0.21-robik_020                                          */
/*----------------------------------------------------------------------------*/
//
// Grid Instance Generator - main program.
//
// Generated a Multi Robot instance on a 4-connected grid with randomly
// placed obstacles.
//
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

#include "config.h"
#include "reLoc_compile.h"
#include "defs.h"
#include "reloc.h"
#include "multirobot.h"
#include "compress.h"
#include "statistics.h"
#include "version.h"

#include "gridgen_main.h"


using namespace sReloc;


/*----------------------------------------------------------------------------*/

namespace sReloc
{


/*----------------------------------------------------------------------------*/

  sCommandParameters::sCommandParameters()
      : m_disjoint(false)
      , m_walk(false)
      , m_distance(-1)
      , m_x_size(4)
      , m_y_size(4)
      , m_N_robots(5)
      , m_N_goals(1)
      , m_seed(0)
      , m_N_fixed(0)
      , m_range(0)
      , m_obstacle_probability(0.1)
      , m_N_obstacles(-1)
      , m_cnf_level(6)
      , m_capacity(1)
      , m_directed(false)
  {
      // nothing
  }


/*----------------------------------------------------------------------------*/

    void print_IntroductoryMessage(void)
    {
	printf("================================================================\n");
	printf("%s : Grid Instance Generator\n", sPRODUCT);
	printf("%s\n", sCOPYRIGHT);
	printf("----------------------------------------------------------------\n");
    }


    void print_ConcludingMessage(void)
    {
	printf("----------------------------------------------------------------\n");
    }


    void print_Help(void)
    {
	printf("Usage:\n");
	printf("gridgen_reLOC  --x-size=<int>\n");
	printf("               --y-size=<int>\n");
	printf("               --N-robots=<int>\n");
	printf("              [--N-goals=<int>]\n");
	printf("               --N-fixed=<int>\n");
	printf("               --obstacle-probability=<double>\n");
	printf("               --N-obstacles=<int>\n");
	printf("               --cnf-file=<string>\n");
	printf("               --cnf-level=<int>\n");
	printf("              [--capacity=<int>]\n");	
	printf("              [--range=<int>]\n");	
	printf("              [--seed=<int>]\n");
	printf("              [--pddl-domain-file=<string>]\n");
	printf("              [--pddl-problem-file=<string>]\n");
	printf("              [--bgu-file=<string>]\n");
	printf("              [--map-file=<string>]\n");
	printf("              [--multirobot-file=<string>]\n");
	printf("              [--usc-map-file=<string>]\n");
	printf("              [--usc-agents-file=<string>]\n");		
	printf("               --disjoint\n");
	printf("               --walk\n");
	printf("               --distance=<int>\n");
	printf("               --directed\n");
	printf("\n");
	printf("Examples:\n");
	printf("gridgen_reLOC --x-size=4\n");
	printf("              --y-size=4\n");
	printf("              --N-robots=5\n");
	printf("              --N-goals=2\n");
	printf("              --seed=12345\n");
	printf("              --obstacle-probability=0.1\n");
	printf("              --cnf-file=mrpp_4x4#5_6.cnf\n");
	printf("              --cnf-level=6\n");
	printf("\n");
	printf("Defaults: --x-size=4\n");
	printf("          --y-size=4\n");
	printf("          --N-robots=5\n");
	printf("          --N-goals=1\n");
	printf("          --N-fixed=0\n");
	printf("          --range=0\n");
	printf("          --capacity=1\n");	
	printf("          --seed=0\n");
	printf("          --obstacle-probability=0.1\n");
	printf("          --cnf-level=6\n");
	printf("\n");
    }


    sResult generate_GridInstance(const sCommandParameters &parameters)
    {
	sResult result;

	srand(parameters.m_seed);

	sMultirobotInstance instance;
	sUndirectedGraph environment(parameters.m_directed);

	if (!parameters.m_usc_map_filename.empty())
	{
	    if (!parameters.m_usc_agents_filename.empty())
	    {
		result = instance.from_File_usc(parameters.m_usc_map_filename, parameters.m_usc_agents_filename);

		if (sFAILED(result))
		{
		    printf("Error: Failed to read usc map and agents files %s,%s (code = %d).\n", parameters.m_usc_map_filename.c_str(), parameters.m_usc_agents_filename.c_str(), result);
		    return result;
		}
		instance.to_Screen();
	    }
	    else		
	    {
		result = environment.from_File_usc(parameters.m_usc_map_filename);
				
		if (parameters.m_range > 0)
		{
		    environment.explicate_Conflicts(parameters.m_range);
		}	
		sRobotArrangement initial_arrangement;
		
		if (sFAILED(result = initial_arrangement.generate_Nonconflicting(environment.get_VertexCount(), sMIN(parameters.m_N_robots, environment.get_VertexCount()), environment)))
		{
		    printf("Error: Failed to generate initial arrangement because of too many conflicts.\n");
		    return result;
		}
		sRobotArrangement goal_arrangement(environment.get_VertexCount(), parameters.m_N_robots);		
		goal_arrangement.generate_NovelNonconflictingWalk(initial_arrangement, environment);
		instance = sMultirobotInstance(environment, initial_arrangement, goal_arrangement);
	    }
	}
	else
	{       
	    if (!parameters.m_map_filename.empty())
	    {	    
		result = environment.from_File_map(parameters.m_map_filename);
		
		if (sFAILED(result))
		{
		    printf("Error: Failed to read map file %s (code = %d).\n", parameters.m_map_filename.c_str(), result);
		    return result;
		}
	    }
	    else
	    {
		if (parameters.m_N_obstacles != -1)
		{
		    environment = sUndirectedGraph(parameters.m_directed, parameters.m_x_size, parameters.m_y_size, parameters.m_N_obstacles);
		}
		else
		{
		    environment = sUndirectedGraph(parameters.m_directed, parameters.m_x_size, parameters.m_y_size, parameters.m_obstacle_probability);
		}
	    }
	    sRobotArrangement initial_arrangement(environment.get_VertexCount(), sMIN(parameters.m_N_robots, environment.get_VertexCount()), true);
	    
	    if (parameters.m_walk)
	    {
		if (parameters.m_disjoint)
		{
		    sASSERT(false);
		}
		else
		{
		    if (parameters.m_N_goals > 1)
		    {
			sASSERT(false);
		    }
		    else
		    {
			if (parameters.m_N_fixed > 0)
			{
			    sRobotArrangement goal_arrangement(environment.get_VertexCount(), parameters.m_N_robots);
			    goal_arrangement.generate_Walk(initial_arrangement, environment, parameters.m_N_fixed);
			    instance = sMultirobotInstance(environment, initial_arrangement, goal_arrangement);
			}
			else
			{
			    sRobotArrangement goal_arrangement(environment.get_VertexCount(), parameters.m_N_robots);
			    goal_arrangement.generate_NovelWalk(initial_arrangement, environment);
			    instance = sMultirobotInstance(environment, initial_arrangement, goal_arrangement);
			}
		    }
		}
	    }
	    else if (parameters.m_distance != -1)
	    {
		if (parameters.m_disjoint)
		{
		    sASSERT(false);
		}
		else
		{
		    if (parameters.m_N_goals > 1)
		    {
			sASSERT(false);
		    }
		    else
		    {
			if (parameters.m_N_fixed > 0)
			{
			    sASSERT(false);
			}
			else
			{
			    sRobotArrangement goal_arrangement(environment.get_VertexCount(), parameters.m_N_robots);
			    goal_arrangement.generate_Equidistant(initial_arrangement, environment, parameters.m_distance);
			    instance = sMultirobotInstance(environment, initial_arrangement, goal_arrangement);
			}
		    }
		}
	    }
	    else
	    {
		if (parameters.m_disjoint)
		{
		    if (parameters.m_N_goals > 1)
		    {
			sRobotGoal goal_specification(initial_arrangement, environment.get_VertexCount(), sMIN(parameters.m_N_robots, environment.get_VertexCount()), parameters.m_N_goals);
			instance = sMultirobotInstance(environment, initial_arrangement, goal_specification);
		    }
		    else
		    {
			sRobotArrangement goal_arrangement(initial_arrangement, environment.get_VertexCount(), sMIN(parameters.m_N_robots, environment.get_VertexCount()), parameters.m_N_fixed, true);
			instance = sMultirobotInstance(environment, initial_arrangement, goal_arrangement);
		    }
		    
		}
		else
		{
		    if (parameters.m_N_goals > 1)
		    {
			sRobotGoal goal_specification(environment.get_VertexCount(), sMIN(parameters.m_N_robots, environment.get_VertexCount()), parameters.m_N_goals);
			instance = sMultirobotInstance(environment, initial_arrangement, goal_specification);
		    }
		    else
		    {
			if (parameters.m_N_fixed > 0)
			{
			    sRobotArrangement goal_arrangement(initial_arrangement, environment.get_VertexCount(), sMIN(parameters.m_N_robots, environment.get_VertexCount()), parameters.m_N_fixed, true);
			    instance = sMultirobotInstance(environment, initial_arrangement, goal_arrangement);
			}
			else
			{
			    sRobotArrangement goal_arrangement(environment.get_VertexCount(), sMIN(parameters.m_N_robots, environment.get_VertexCount()), true);
			    instance = sMultirobotInstance(environment, initial_arrangement, goal_arrangement);
			}
		    }
		}
	    }
	    if (parameters.m_range > 0)
	    {
		instance.m_environment.explicate_Conflicts(parameters.m_range);
	    }
	    if (parameters.m_capacity > 1)
	    {
		instance.m_environment.set_Capacities(parameters.m_capacity);
	    }	    
	}
	
	if (!parameters.m_cnf_filename.empty())
	{
	    sMultirobotEncodingContext_CNFsat encoding_context(parameters.m_cnf_level);

	    //result = instance.to_File_HeuristicAdvancedCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_AdvancedCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_InverseCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_HeuristicDifferentialCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_FlowCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_HeuristicMatchingCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_DifferentialCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_MatchingCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_DirectCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_HeuristicDirectCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_SimplicialCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_HeuristicSimplicialCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_SingularCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    //result = instance.to_File_PluralCNFsat(parameters.m_cnf_filename, encoding_context, "");
	    result = instance.to_File_Plural2CNFsat(parameters.m_cnf_filename, encoding_context, "");

	    if (sFAILED(result))
	    {
		printf("Error: Failed to write CNF file %s (code = %d).\n", parameters.m_cnf_filename.c_str(), result);
		return result;
	    }
	}
	if (!parameters.m_pddl_problem_filename.empty())
	{
	    result = instance.to_File_problemPDDL(parameters.m_pddl_problem_filename);

	    if (sFAILED(result))
	    {
		printf("Error: Failed to write PDDL problem file %s (code = %d).\n", parameters.m_pddl_problem_filename.c_str(), result);
		return result;
	    }
	}
	if (!parameters.m_pddl_domain_filename.empty())
	{
	    result = instance.to_File_domainPDDL(parameters.m_pddl_domain_filename);

	    if (sFAILED(result))
	    {
		printf("Error: Failed to write PDDL domain file %s (code = %d).\n", parameters.m_pddl_domain_filename.c_str(), result);
		return result;
	    }
	}
	if (!parameters.m_multirobot_filename.empty())
	{
	    if (parameters.m_capacity > 1)
	    {
		result = instance.to_File_capacitated_multirobot(parameters.m_multirobot_filename);
	    }
	    else
	    {
		result = instance.to_File_multirobot(parameters.m_multirobot_filename);
	    }

	    if (sFAILED(result))
	    {
		printf("Error: Failed to write multirobot file %s (code = %d).\n", parameters.m_multirobot_filename.c_str(), result);
		return result;
	    }
	}
	if (!parameters.m_bgu_filename.empty())
	{
	    result = instance.to_File_bgu(parameters.m_bgu_filename, "", 1);

	    if (sFAILED(result))
	    {
		printf("Error: Failed to write multirobot file %s (code = %d).\n", parameters.m_bgu_filename.c_str(), result);
		return result;
	    }
	}
	#ifdef sSTATISTICS
	{
	  s_GlobalPhaseStatistics.to_Screen();
	}
	#endif

	return sRESULT_SUCCESS;
    }


    sResult parse_CommandLineParameter(const sString &parameter, sCommandParameters &command_parameters)
    {
	if (parameter.find("--x-size=") == 0)
	{
	    command_parameters.m_x_size = sInt_32_from_String(parameter.substr(9, parameter.size()));
	}
	else if (parameter.find("--y-size=") == 0)
	{
	    command_parameters.m_y_size = sInt_32_from_String(parameter.substr(9, parameter.size()));
	}
	else if (parameter.find("--N-robots=") == 0)
	{
	    command_parameters.m_N_robots = sInt_32_from_String(parameter.substr(11, parameter.size()));
	}
	else if (parameter.find("--N-goals=") == 0)
	{
	    command_parameters.m_N_goals = sInt_32_from_String(parameter.substr(10, parameter.size()));
	}
	else if (parameter.find("--N-fixed=") == 0)
	{
	    command_parameters.m_N_fixed = sInt_32_from_String(parameter.substr(10, parameter.size()));
	}
	else if (parameter.find("--range=") == 0)
	{
	    command_parameters.m_range = sInt_32_from_String(parameter.substr(8, parameter.size()));
	}
	else if (parameter.find("--capacity=") == 0)
	{
	    command_parameters.m_capacity = sInt_32_from_String(parameter.substr(11, parameter.size()));
	}		
	else if (parameter.find("--seed=") == 0)
	{
	    command_parameters.m_seed = sInt_32_from_String(parameter.substr(7, parameter.size()));
	}
	else if (parameter.find("--obstacle-probability=") == 0)
	{
	    command_parameters.m_obstacle_probability = sDouble_from_String(parameter.substr(23, parameter.size()));
	}
	else if (parameter.find("--N-obstacles=") == 0)
	{
	    command_parameters.m_N_obstacles = sInt_32_from_String(parameter.substr(14, parameter.size()));
	}
	else if (parameter.find("--cnf-level=") == 0)
	{
	    command_parameters.m_cnf_level = sInt_32_from_String(parameter.substr(12, parameter.size()));
	}
	else if (parameter.find("--directed") == 0)
	{
	    command_parameters.m_directed = true;
	}	
	else if (parameter.find("--cnf-file=") == 0)
	{
	    command_parameters.m_cnf_filename = parameter.substr(11, parameter.size());
	}
	else if (parameter.find("--pddl-domain-file=") == 0)
	{
	    command_parameters.m_pddl_domain_filename = parameter.substr(19, parameter.size());
	}
	else if (parameter.find("--pddl-problem-file=") == 0)
	{
	    command_parameters.m_pddl_problem_filename = parameter.substr(20, parameter.size());
	}
	else if (parameter.find("--multirobot-file=") == 0)
	{
	    command_parameters.m_multirobot_filename = parameter.substr(18, parameter.size());
	}
	else if (parameter.find("--map-file=") == 0)
	{
	    command_parameters.m_map_filename = parameter.substr(11, parameter.size());
	}
	else if (parameter.find("--usc-map-file=") == 0)
	{
	    command_parameters.m_usc_map_filename = parameter.substr(15, parameter.size());
	}
	else if (parameter.find("--usc-agents-file=") == 0)
	{
	    command_parameters.m_usc_agents_filename = parameter.substr(18, parameter.size());
	}		
	else if (parameter.find("--bgu-file=") == 0)
	{
	    command_parameters.m_bgu_filename = parameter.substr(11, parameter.size());
	}
	else if (parameter.find("--dibox-file=") == 0)
	{
	    command_parameters.m_dibox_filename = parameter.substr(13, parameter.size());
	}	
	else if (parameter.find("--disjoint") == 0)
	{
	    command_parameters.m_disjoint = true;
	}
	else if (parameter.find("--walk") == 0)
	{
	    command_parameters.m_walk = true;
	}
	else if (parameter.find("--distance=") == 0)
	{
	    command_parameters.m_distance = sInt_32_from_String(parameter.substr(11, parameter.size()));
	}
	else
	{
	    return sRESOLVER_PROGRAM_UNRECOGNIZED_PARAMETER_ERROR;
	}
	return sRESULT_SUCCESS;
    }


/*----------------------------------------------------------------------------*/

} // namespace sReloc


/*----------------------------------------------------------------------------*/
// main program

int main(int argc, char **argv)
{
    sResult result;
    sCommandParameters command_parameters;

    print_IntroductoryMessage();

    if (argc >= 2 && argc <= 11)
    {
	for (int i = 1; i < argc; ++i)
	{
	    result = parse_CommandLineParameter(argv[i], command_parameters);
	    if (sFAILED(result))
	    {
		printf("Error: Cannot parse command line parameters (code = %d).\n", result);
		print_Help();

		return result;
	    }
	}
	result = generate_GridInstance(command_parameters);
	if (sFAILED(result))
	{
	    return result;
	}
    }
    else
    {
	print_Help();
    }
    return sRESULT_SUCCESS;
}

