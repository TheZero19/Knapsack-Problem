#include "pch.h"
#include "knapsack.h"


TEST(TestCaseName, GREEDYFractionalKnapsack_test1) {

  //Creating instances of ItemCostProfit type to create individual items with cost and profit.
  ItemCostProfit item1(10, 14);
  ItemCostProfit item2(7, 12);
  ItemCostProfit item3(10, 16);
  ItemCostProfit item4(9, 15);
  ItemCostProfit item5(6, 19);


  //Instantiating a variable of CostProfitData user-defined type
  CostProfitData_GreedyMethod cpd;
  CostProfitData_BruteForce_zeroOneKnapsack cpdBF;
  CostProfitData_BruteForce_fractionalKnapsack cpdBFFK;

  //adding data to the vector
  cpd.inputData(item1);
  cpd.inputData(item2);
  cpd.inputData(item3);
  cpd.inputData(item4);
  cpd.inputData(item5);

  cpdBF.inputData(item1);
  cpdBF.inputData(item2);
  cpdBF.inputData(item3);
  cpdBF.inputData(item4);
  cpdBF.inputData(item5);

  cpdBFFK.inputData(item1);
  cpdBFFK.inputData(item2);
  cpdBFFK.inputData(item3);
  cpdBFFK.inputData(item4);
  cpdBFFK.inputData(item5);

  EXPECT_EQ(cpd.maxProfit_Calculate(16, 5), cpd.maxProfit_Calculate (10, 5)); //must result in different outcomes as the knapsack capacity doesn't even come close.
}

TEST(TestCaseName, GREEDYFractionalKnapsack_test2) {

	//Creating instances of ItemCostProfit type to create individual items with cost and profit.
	ItemCostProfit item1(10, 14);
	ItemCostProfit item2(7, 12);
	ItemCostProfit item3(10, 16);
	ItemCostProfit item4(9, 15);
	ItemCostProfit item5(6, 19);


	//Instantiating a variable of CostProfitData user-defined type
	CostProfitData_GreedyMethod cpd;
	CostProfitData_BruteForce_zeroOneKnapsack cpdBF;
	CostProfitData_BruteForce_fractionalKnapsack cpdBFFK;

	//adding data to the vector
	cpd.inputData(item1);
	cpd.inputData(item2);
	cpd.inputData(item3);
	cpd.inputData(item4);
	cpd.inputData(item5);

	cpdBF.inputData(item1);
	cpdBF.inputData(item2);
	cpdBF.inputData(item3);
	cpdBF.inputData(item4);
	cpdBF.inputData(item5);

	cpdBFFK.inputData(item1);
	cpdBFFK.inputData(item2);
	cpdBFFK.inputData(item3);
	cpdBFFK.inputData(item4);
	cpdBFFK.inputData(item5);

	EXPECT_EQ(cpd.maxProfit_Calculate(16, 5), 36); //the test must come true as the outcome for the given data for greedy fractional knapsack was 36
}

TEST(TestCaseName, bothFractionalKnapsackImplementationTest) {

	//Creating instances of ItemCostProfit type to create individual items with cost and profit.
	ItemCostProfit item1(10, 14);
	ItemCostProfit item2(7, 12);
	ItemCostProfit item3(10, 16);
	ItemCostProfit item4(9, 15);
	ItemCostProfit item5(6, 19);


	//Instantiating a variable of CostProfitData user-defined type
	CostProfitData_GreedyMethod cpd;
	CostProfitData_BruteForce_zeroOneKnapsack cpdBF;
	CostProfitData_BruteForce_fractionalKnapsack cpdBFFK;

	//adding data to the vector
	cpd.inputData(item1);
	cpd.inputData(item2);
	cpd.inputData(item3);
	cpd.inputData(item4);
	cpd.inputData(item5);

	cpdBF.inputData(item1);
	cpdBF.inputData(item2);
	cpdBF.inputData(item3);
	cpdBF.inputData(item4);
	cpdBF.inputData(item5);

	cpdBFFK.inputData(item1);
	cpdBFFK.inputData(item2);
	cpdBFFK.inputData(item3);
	cpdBFFK.inputData(item4);
	cpdBFFK.inputData(item5);

	EXPECT_EQ(cpd.maxProfit_Calculate(16, 5), cpdBFFK.maxProfit_Calculate(16, 5)); //the test must come true theoretically but will be false for fractional knapsack as greedy approach is only a suboptimal approach
}

TEST(TestCaseName, bruteforceKnapsack) {

	//Creating instances of ItemCostProfit type to create individual items with cost and profit.
	ItemCostProfit item1(10, 14);
	ItemCostProfit item2(7, 12);
	ItemCostProfit item3(10, 16);
	ItemCostProfit item4(9, 15);
	ItemCostProfit item5(6, 19);


	//Instantiating a variable of CostProfitData user-defined type
	CostProfitData_GreedyMethod cpd;
	CostProfitData_BruteForce_zeroOneKnapsack cpdBF;
	CostProfitData_BruteForce_fractionalKnapsack cpdBFFK;

	//adding data to the vector
	cpd.inputData(item1);
	cpd.inputData(item2);
	cpd.inputData(item3);
	cpd.inputData(item4);
	cpd.inputData(item5);

	cpdBF.inputData(item1);
	cpdBF.inputData(item2);
	cpdBF.inputData(item3);
	cpdBF.inputData(item4);
	cpdBF.inputData(item5);

	cpdBFFK.inputData(item1);
	cpdBFFK.inputData(item2);
	cpdBFFK.inputData(item3);
	cpdBFFK.inputData(item4);
	cpdBFFK.inputData(item5);

	EXPECT_EQ(cpdBF.maxProfit_Calculate(16, 5), cpdBFFK.maxProfit_Calculate(16, 5)); //since both follow the bruteforce approach, the results should align
}





int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}