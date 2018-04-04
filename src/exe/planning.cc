#include <ompl/base/SpaceInformation.h>
#include <ompl/base/spaces/RealVectorStateSpace.h>
//#include <ompl/geometric/planners/rrt/RRTConnect.h>
#include <ompl/geometric/SimpleSetup.h>
#include <ompl/geometric/planners/rrt/RRT.h>

#include <ompl/config.h>
#include <iostream>

#include "src/planner/RRT.h"

using namespace std;
namespace ob = ompl::base;
namespace og = ompl::geometric;

bool isStateValid(const ob::State *state)
{
    /*// cast the abstract state type to the type we expect
    const auto *se3state = state->as<ob::SE3StateSpace::StateType>();

    // extract the first component of the state and cast it to what we expect
    const auto *pos = se3state->as<ob::RealVectorStateSpace::StateType>(0);

    // extract the second component of the state and cast it to what we expect
    const auto *rot = se3state->as<ob::SO3StateSpace::StateType>(1);

    // check validity of state defined by pos & rot


    // return a value that is always true but uses the two variables we define, so we avoid compiler warnings
    return (const void*)rot != (const void*)pos;*/
    
    
    //check if the fucking state is valid here.
    return true;
}

og::SimpleSetup pointRobotWorkspace2D(){
	//space type
	auto space(std::make_shared<ob::RealVectorStateSpace>());
	
	//bounds
    space->addDimension("x", -1, 1);
    space->addDimension("y", -1, 1);
    
    //using simple setup to build space
    og::SimpleSetup ss(space);
    
    // set state validity checking for this space
    ss.setStateValidityChecker([](const ob::State *state) { return isStateValid(state); });
    
    // change this to use our own start point
    ob::ScopedState<> start(space);
    start.random();

    // change this to use our own goal point
    ob::ScopedState<> goal(space);
    goal.random();
    
    // set the start and goal states
    ss.setStartAndGoalStates(start, goal);
    
    return ss;
    
}

int main(int argc, char ** argv)
{	
	og::SimpleSetup ss = pointRobotWorkspace2D();
	
	auto myRRT(std::make_shared<og::MyRRT>(ss.getSpaceInformation()));
    
    ss.setPlanner(myRRT);
    
    ob::PlannerStatus solved = ss.solve(1.0);
    
    if (solved)
    {
        /*std::cout << "Found solution:" << std::endl;
        // print the path to screen
        ss.simplifySolution();
        ss.getSolutionPath().print(std::cout);*/
        //do something, printing time, visulizing path
    }
    else
        std::cout << "No solution found" << std::endl;

    return 0;
}
