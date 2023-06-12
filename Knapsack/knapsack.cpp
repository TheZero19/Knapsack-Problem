#include "pch.h"
#include<algorithm>
#include"knapsack.h"

void CostProfitData::inputData(ItemCostProfit itemCostProfit) {
	this->costProfitCollection.push_back(itemCostProfit);
}

void CostProfitData::outputData() {
	/*for (auto i = costProfitInfo.begin(); i != costProfitInfo.end(); ++i) {
		std::cout << "Cost = " << (*i).cost << ", Profit = " << (*i).profit << std::endl;
	}*/
	for (int i = 0; i < costProfitCollection.size(); i++) {
		std::cout << "Cost = " << costProfitCollection[i].cost <<
			", Profit = " << costProfitCollection[i].profit <<
			", PPUC = " << costProfitCollection[i].profitPerUnitCost << std::endl;
	}
}

void CostProfitData::sorting_inDescending() {
	//using insertion sort to sort the item on the basis of the profitPerUnitCost but in descending order:
	//first sort according to the profitPerUnitCost and then reverse the order of the vector.

	ItemCostProfit temp;
	int j;
	for (int i = 1; i < costProfitCollection.size(); i++) {
		temp = costProfitCollection[i];
		j = i - 1;
		while (j > 0 && costProfitCollection[j].profitPerUnitCost > temp.profitPerUnitCost) {
			costProfitCollection[j + 1] = costProfitCollection[j];
			j = j - 1;
			costProfitCollection[j + 1] = temp;
		}
	}
	reverse(costProfitCollection.begin(), costProfitCollection.end());
}

float CostProfitData_GreedyMethod::maxProfit_Calculate(float knapsackCapacity, int size) {

	sorting_inDescending();
	this->costProfitInfo = costProfitCollection; //updating the order of the items

	std::vector<ItemCostProfit> items_inKnapsack;

	float remainingCapacity = knapsackCapacity; //to keep track of remaining capacity of our sack.

	float max_profit = 0;

	for (int i = 0; i < costProfitInfo.size(); i++) {
		if (remainingCapacity >= costProfitInfo[i].cost) {
			items_inKnapsack.push_back(costProfitInfo[i]);
			costProfitInfo[i].includedInKnapsack = true;
			max_profit += costProfitInfo[i].profit;
			remainingCapacity -= costProfitInfo[i].cost;
		}
		else {
			//if the item's cost exceeds the capacity of knapsack,
			//find the fractional cost and fractional profit.
			ItemCostProfit fractional;
			fractional.cost = remainingCapacity;
			fractional.profitPerUnitCost = costProfitInfo[i].profitPerUnitCost;
			fractional.profit = fractional.cost * fractional.profitPerUnitCost;
			items_inKnapsack.push_back(fractional);
			costProfitInfo[i].includedInKnapsack = true;
			max_profit += fractional.profit;
			remainingCapacity = 0;
		}
	}

	return max_profit;
}

float CostProfitData_BruteForce_zeroOneKnapsack::maxProfit_Calculate(float knapsackCapacity, int size) {
	int numItems = std::min(size, static_cast<int>(costProfitCollection.size()));  // Consider the minimum of size and vector size
	int maxProfit = 0;

	//generate all the combinations
	for (int i = 0; i < (1 << numItems); i++) {
		float totalCost = 0;
		float totalProfit = 0;

		for (int j = 0; j < numItems; j++) {
			// Check if the jth item is included in the current subset
			if (i & (1 << j)) {
				totalCost += costProfitCollection[j].cost;
				totalProfit += costProfitCollection[j].profit;
			}
		}

		// Update max value if the total weight is within the capacity
		if (totalCost <= knapsackCapacity && totalProfit > maxProfit) {
			maxProfit = totalProfit;

			// Update includedInKnapsack flag for the items
			for (int j = 0; j < numItems; j++) {
				costProfitCollection[j].includedInKnapsack = (i & (1 << j)) ? true : false;
			}
		}
	}

	return maxProfit;
}

float CostProfitData_BruteForce_fractionalKnapsack::maxProfit_Calculate(float knapsackCapacity, int size) {
	int numItems = std::min(size, static_cast<int>(costProfitCollection.size()));
	float maxProfit = 0;

	// Generate all possible subsets of items
	for (int i = 0; i < (1 << numItems); i++) {
		float totalCost = 0;
		float totalProfit = 0;

		for (int j = 0; j < numItems; j++) {
			// Check if the jth item is included in the current subset
			if (i & (1 << j)) {
				totalCost += costProfitCollection[j].cost;
				totalProfit += costProfitCollection[j].profit;
			}
		}

		// Check if the total weight exceeds the knapsack capacity
		if (totalCost > knapsackCapacity) {
			continue;
		}

		// Calculate the remaining capacity after including integer-weighted items
		float remainingCapacity = knapsackCapacity - totalCost;

		// Include the fractional part of the next item if it can be fully or partially included
		if (numItems < costProfitCollection.size() && remainingCapacity > 0) {
			float fraction = remainingCapacity;
			float fractionalProfit = fraction * costProfitCollection[numItems].profitPerUnitCost;
			remainingCapacity = 0;
			totalProfit += fractionalProfit;
		}

		// Update max profit if the total profit is higher
		if (totalProfit > maxProfit) {
			maxProfit = totalProfit;

			// Update "includedInKnapsack" flags for the items
			for (int j = 0; j < numItems; j++) {
				costProfitCollection[j].includedInKnapsack = (i & (1 << j)) ? true : false;
			}

			// Update taken flag for the fractional item
			if (numItems < costProfitCollection.size()) {
				costProfitCollection[numItems].includedInKnapsack = true;
			}
		}
	}

	return maxProfit;
}