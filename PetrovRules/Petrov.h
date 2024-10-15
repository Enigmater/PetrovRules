#pragma once
#include <vector>;
class Petrov
{
private:
	std::vector<int> rule1();
	std::vector<int> rule2();
	std::vector<int> rule3();
	std::vector<int> rule4();

	void ReadFile(const char* filename = "input.txt");
	void setParams();
	void setSeqs();

	std::vector<std::vector<int>> idleTime;
	std::vector<std::vector<int>> finishTime;
	std::vector<int> order;

public:
	std::vector<std::vector<int>> data;
	std::vector<std::vector<int>> params;
	std::vector<std::vector<int>> seqs;

	void setSeq(int seq);
	void setSeq(std::vector<int> order);

	int getMachineIdleTime();
	int getWaitTime();

	int getFinishTime();

	void resetIdleTime();
	void resetFinishTime();

	int getIdleTime(int i, int j);
	int getOrderID(int i);

	Petrov(const char* filename = "input.txt");
	~Petrov() {};
};

