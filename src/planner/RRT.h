#ifndef PLANNER_RRT_
#define PLANNER_RRT_

#include <ompl/datastructures/NearestNeighbors.h>
#include <ompl/geometric/planners/PlannerIncludes.h>
#include <ompl/base/SpaceInformation.h>

namespace ompl
{
	namespace geometric
	{
		class MyRRT : public base::Planner
		{
		public:
			
			MyRRT(const base::SpaceInformationPtr &si);

			~MyRRT() override;

			void getPlannerData(base::PlannerData &data) const override;

			base::PlannerStatus solve(const base::PlannerTerminationCondition &ptc) override;

			void clear() override;

			void setup() override;

		protected:
			
		};
	}
}

#endif
