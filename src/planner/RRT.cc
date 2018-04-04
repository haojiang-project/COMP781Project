// often useful headers:
#include <ompl/util/RandomNumbers.h>
#include <ompl/tools/config/SelfConfig.h>
#include <limits>
#include <ompl/base/goals/GoalSampleableRegion.h>

#include "RRT.h"

namespace og = ompl::geometric;
	
og::MyRRT::MyRRT(const base::SpaceInformationPtr &si) : base::Planner(si, "MyRRT")
{
	// the specifications of this planner (ompl::base::PlannerSpecs)
	specs_.approximateSolutions = true;
	specs_.directed = true;
	//specs_.recognizedGoal = true;
}
og::MyRRT::~MyRRT(void)
{
	// free any allocated memory
}
ompl::base::PlannerStatus og::MyRRT::solve(const base::PlannerTerminationCondition &ptc)
{
	// make sure the planner is configured correctly; ompl::base::Planner::checkValidity
	// ensures that there is at least one input state and a ompl::base::Goal object specified
	checkValidity();
	// get a handle to the Goal from the ompl::base::ProblemDefinition member, pdef_
	base::Goal *goal = pdef_->getGoal().get();
	// get input states with PlannerInputStates helper, pis_
	while (const base::State *st = pis_.nextStart())
	{
		// st will contain a start state.  Typically this state will
		// be cloned here and inserted into the Planner's data structure.
	}
	// if needed, sample states from the goal region (and wait until a state is sampled)
	const base::State *st = pis_.nextGoal(ptc);
	// periodically check if ptc() returns true.
	// if it does, terminate planning.
	while (ptc() == false)
	{
		// Start planning here.
		// call routines from SpaceInformation (si_) as needed. i.e.,
		// si_->allocStateSampler() for sampling,
		// si_->checkMotion(state1, state2) for state validity, etc...
		// use the Goal pointer to evaluate whether a sampled state satisfies the goal requirements
		// use log macros for informative messaging, i.e., logInfo("Planner found a solution!");
	}
	// When a solution path is computed, save it here
	//pdef_->addSolutionPath(...);
	// Return a value from the PlannerStatus enumeration.
	// See ompl::base::PlannerStatus for the possible return values
	return base::PlannerStatus::EXACT_SOLUTION;
}
void og::MyRRT::clear(void)
{
	Planner::clear();
	// clear the data structures here
}
// optional, if additional setup/configuration is needed, the setup() method can be implemented
void og::MyRRT::setup(void)
{
	Planner::setup();
	// perhaps attempt some auto-configuration
	tools::SelfConfig sc(si_, getName());
	//sc.configure...
}
void og::MyRRT::getPlannerData(base::PlannerData &data) const
{
	// fill data with the states and edges that were created
	// in the exploration data structure
	// perhaps also fill control::PlannerData
}
