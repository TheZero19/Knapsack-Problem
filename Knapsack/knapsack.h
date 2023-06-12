#pragma once
#include "pch.h"
#include<iostream>
#include<vector>


//a class that stores the cost of an item and its profit
class ItemCostProfit {
public:
	//publicly defining data members so that it can be accessible by another class.
	float cost;
	float profit;
	float profitPerUnitCost;
	bool includedInKnapsack = false; //at first, no items are selected in knapsack

public:
	ItemCostProfit() {
		this->cost = 0;
		this->profit = 0;
		this->profitPerUnitCost = 0;
	}

	ItemCostProfit(float cost, float profit) {
		this->cost = cost;
		this->profit = profit;
		this->profitPerUnitCost = (profit / cost);
	}
};


class CostProfitData {
protected:
	std::vector<ItemCostProfit> costProfitCollection;

public:
	void inputData(ItemCostProfit itemCostProfit);
	void outputData();
	void sorting_inDescending();
	virtual float maxProfit_Calculate(float knapsackCapacity, int size) = 0;
};

//a class that maintains a vector that stores multiple ItemCostProfit type
class CostProfitData_GreedyMethod : public CostProfitData {
private:
	std::vector<ItemCostProfit> costProfitInfo = costProfitCollection;
public:
	float maxProfit_Calculate(float knapsackCapacity, int size);
};

class CostProfitData_BruteForce_zeroOneKnapsack : public CostProfitData {
	//private:
	//	std::vector<ItemCostProfit> costProfitInfo = costProfitCollection;

public:
	//float fractionalKnapsack_maxProfit_Calculate(float knapsackCapacity);
	float maxProfit_Calculate(float knapsackCapacity, int size);
};

class CostProfitData_BruteForce_fractionalKnapsack : public CostProfitData {
public:
	float maxProfit_Calculate(float knapsackCapacity, int size);
};
