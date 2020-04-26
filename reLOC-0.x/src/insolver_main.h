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
/* insolver_main.h / 0.21-robik_020                                           */
/*----------------------------------------------------------------------------*/
//
// Solution generator - main program.
//
// Solves a given multirobot instance by the SAT solving technique from scratch.
// SATPlan iterative solution length increasing is adopted.
//
//
/*----------------------------------------------------------------------------*/


#ifndef __INSOLVER_MAIN_H__
#define __INSOLVER_MAIN_H__

#include "reloc.h"

using namespace sReloc;


/*----------------------------------------------------------------------------*/

namespace sReloc
{


/*----------------------------------------------------------------------------*/

    struct sCommandParameters
    {
	enum BaseStrategy
	{
	    STRATEGY_UNDEFINED,
	    STRATEGY_LINEAR_DOWN,
	    STRATEGY_LINEAR_UP,
	    STRATEGY_BINARY	    
	};

	enum Completion
	{
	    COMPLETION_UNDEFINED,
	    COMPLETION_SIMULTANEOUS,
	    COMPLETION_UNIROBOT,
	    COMPLETION_WHCA,
	    COMPLETION_COMPLETE
	};

	sCommandParameters();
        /*--------------------------------*/

	BaseStrategy m_base_strategy;
	Completion m_completion;
	sMultirobotSolutionCompressor::Encoding m_cnf_encoding;

	int m_makespan_upper_bound;
	int m_makespan_specified;	
	int m_layer_upper_bound;
	int m_total_cost_bound;
	int m_total_fuel_bound;	
	int m_minisat_timeout;
	int m_total_timeout;

	sString m_input_filename;
	sString m_lusc_map_input_filename;
	sString m_lusc_robot_input_filename;	
	sString m_bgu_input;
	sString m_dibox_input;		
	sString m_output_filename;
	sString m_lusc_output_filename;		
	sString m_graphrec_filename;
	sString m_pddl_domain_filename;
	sString m_pddl_problem_filename;

	bool m_independence_detection;
	bool m_avoidance_detection;

	double m_suboptimal_ratio;
	int m_robustness;
	bool m_directed;	
    };


/*----------------------------------------------------------------------------*/

    void print_IntroductoryMessage(void);
    void print_ConcludingMessage(void);
    void print_Help(void);
    
    sResult parse_CommandLineParameter(const sString &parameter, sCommandParameters &parameters);

<<<<<<< HEAD
    sResult solve_MultirobotInstance_SAT(const std::vector<std::pair<int, int> > &obstacles,const  std::vector<std::pair<int, int> > &goals, const std::vector<std::pair<int, int> > &starts, const int &x, const int &y, const std::vector<std::vector<int> > &graph, std::pair<float, std::vector<std::vector<std::tuple<int, int, int> > > > *solution);
=======
    sResult solve_MultirobotInstance_SAT(const std::vector<std::pair<int, int> > &obstacles,const  std::vector<std::pair<int, int> > &goals, const std::vector<std::pair<int, int> > &starts, const int &x, const int &y, const std::vector<std::vector<int> > &graph);
>>>>>>> b8a027dc904c96fd76287b931bf0b0c1bd602221


/*----------------------------------------------------------------------------*/

} // namespace sReloc


#endif /* __INSOLVER_MAIN_H__ */
