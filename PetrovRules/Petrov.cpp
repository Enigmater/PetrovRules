#include "Petrov.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <random>

std::vector<int> Petrov::rule1()
{
	std::vector<int> rule(params.size());
	std::vector<std::vector<int>> D10, D2;

	for (int i = 0; i < params.size(); i++) {
		auto it = params[i];
		if (it[2] >= 0) D10.push_back({ i, it[0], it[1], it[2] });
		else D2.push_back({ i, it[0], it[1], it[2] });
	}
	std::sort(D10.begin(), D10.end(), [](const auto a, const auto b) { return a[1] < b[1]; });
	std::sort(D2.begin(), D2.end(), [](const auto a, const auto b) { return a[2] > b[2]; });

	int seqsit = 0;
	for (int i = 0; i < D10.size(); i++) rule[seqsit++] = D10[i][0];
	for (int i = 0; i < D2.size(); i++) rule[seqsit++] = D2[i][0];

	return rule;
}

std::vector<int> Petrov::rule2()
{
	std::vector<int> rule(params.size());
	std::vector<std::vector<int>> D;

	// D
	for (int i = 0; i < params.size(); i++) {
		auto it = params[i];
		D.push_back({ i, it[0], it[1], it[2] });
	}

	std::sort(D.begin(), D.end(), [](const auto a, const auto b) { return a[3] > b[3]; });
	for (int i = 0; i < D.size(); i++) rule[i] = D[i][0];

	return rule;
}

std::vector<int> Petrov::rule3()
{
	std::vector<int> rule(params.size());
	std::vector<std::vector<int>> D0, D1, D2;

	// D1 (l >= 0)
	for (int i = 0; i < params.size(); i++) {
		auto it = params[i];
		if (it[2] == 0) D0.push_back({ i, it[0], it[1], it[2] });
		else if (it[2] > 0) D1.push_back({ i, it[0], it[1], it[2] });
		else D2.push_back({ i, it[0], it[1], it[2] });
	}

	std::sort(D0.begin(), D0.end(), [](const auto a, const auto b) { return a[1] < b[1]; });
	std::sort(D1.begin(), D1.end(), [](const auto a, const auto b) { return a[1] < b[1]; });
	std::sort(D2.begin(), D2.end(), [](const auto a, const auto b) { return a[2] > b[2]; });

	int seqsit = 0;
	for (int i = 0; i < D1.size(); i++) rule[seqsit++] = D1[i][0];
	for (int i = 0; i < D0.size(); i++) rule[seqsit++] = D0[i][0];
	for (int i = 0; i < D2.size(); i++) rule[seqsit++] = D2[i][0];

	return rule;
}

int findMax(const std::vector<std::vector<int>>& arr, int column, const std::vector<bool>& visited) {
	int max, maxID = -1;
	for (int i = 0; i < arr.size(); i++) if (!visited[arr[i][0]]) { max = arr[i][column]; maxID = arr[i][0]; break; }
	for (int i = 0; i < arr.size(); i++) {
		if (visited[arr[i][0]]) continue;
		if (arr[i][column] > max) {
			max = arr[i][column];
			maxID = arr[i][0];
		}
	}
	return maxID;
}

int findMin(const std::vector<std::vector<int>>& arr, int column, const std::vector<bool>& visited) {
	int min, minID = -1;
	for (int i = 0; i < arr.size(); i++) if (!visited[arr[i][0]]) { min = arr[i][column]; minID = arr[i][0]; break; }
	for (int i = 0; i < arr.size(); i++) {
		if (visited[arr[i][0]]) continue;
		if (arr[i][column] < min) {
			min = arr[i][column];
			minID = arr[i][0];
		}
	}
	return minID;
}

std::vector<int> Petrov::rule4()
{
	std::vector<int> rule;
	std::vector<std::vector<int>> D1, D0, D2;
	for (int i = 0; i < params.size(); i++) {
		auto it = params[i];
		if (it[2] == 0) D0.push_back({ i, it[0], it[1], it[2] });
		if (it[2] > 0) D1.push_back({ i, it[0], it[1], it[2] });
		if (it[2] < 0) D2.push_back({ i, it[0], it[1], it[2] });
	}
	std::vector<bool> visited(data.size(), false);
	for (int i = 0; i < D1.size(); i++) {
		int firstD = findMax(D1, 2, visited);
		if (firstD == -1) break;
		visited[firstD] = true;
		int secondD = findMin(D1, 1, visited);
		if (secondD == -1) {
			visited[firstD] = false;
			break;
		}
		visited[secondD] = true;
		rule.push_back(firstD);
		rule.push_back(secondD);
	}

	if (D1.size() % 2) {
		for (int i = 0; i < D1.size(); i++) {
			if (!visited[D1[i][0]]) {
				rule.push_back(D1[i][0]);
				visited[D1[i][0]] = true;
				int secondD = findMin(D0, 1, visited);
				visited[secondD] = true;
				rule.push_back(secondD);
			}
		}
	}

	for (int i = 0; i < D0.size(); i++) {
		int firstD = findMax(D0, 2, visited);
		if (firstD == -1) break;
		visited[firstD] = true;
		int secondD = findMin(D0, 1, visited);
		if (secondD == -1) {
			visited[firstD] = false;
			break;
		}
		visited[secondD] = true;
		rule.push_back(firstD);
		rule.push_back(secondD);
	}

	if ((D0.size() + D1.size()) % 2) {
		for (int i = 0; i < D0.size(); i++) {
			if (!visited[D0[i][0]]) {
				rule.push_back(D0[i][0]);
				visited[D0[i][0]] = true;
				int secondD = findMin(D2, 1, visited);
				visited[secondD] = true;
				rule.push_back(secondD);
			}
		}
	}

	for (int i = 0; i < D2.size(); i++) {
		int firstD = findMax(D2, 2, visited);
		if (firstD == -1) break;
		visited[firstD] = true;
		int secondD = findMin(D2, 1, visited);
		if (secondD == -1) {
			visited[firstD] = false;
			break;
		}
		visited[secondD] = true;
		rule.push_back(firstD);
		rule.push_back(secondD);
	}

	if (data.size() % 2) {
		int lastId = 0;
		for (int i = 0; i < visited.size(); i++) if (!visited[i]) { lastId = i; break; };
		for (int i = 0; i < rule.size() - 3; i++) {
			if (std::max(params[rule[i]][2], params[rule[i + 1]][2]) >= params[lastId][2] && std::min(params[rule[i + 2]][2], params[rule[i + 3]][2]) <= params[lastId][2]) {
				rule.insert(rule.begin() + i + 2, lastId);
				break;
			}
			else if (i == rule.size() - 4) {
				rule.insert(rule.end(), lastId);
				break;
			}
		}
	}

	return rule;
}

void Petrov::ReadFile(const char* filename)
{
	this->data.clear();
	std::ifstream file(filename);

	std::string line;
	
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::vector<int> row;
		int num;
		while (iss >> num) row.push_back(num);
		
		int m = row.size();

		data.push_back(row);
	}
	file.close();
}

void Petrov::setParams()
{
	int m = data[0].size();
	int n = data.size();

	params.resize(n);
	
	for (int i = 0; i < n; i++) {
		
		auto it = data[i];

		int P1 = 0, P2 = 0;
		int stop = m / 2;
		if (m % 2) stop = (m + 1) / 2;

		for (int j = 0; j < stop; j++) {
			P1 += it[j];
		}
		for (int j = stop - 1; j < m; j++) {
			P2 += it[j];
		}

		int lambda = P2 - P1;

		params[i] = {P1, P2, lambda};
	}
}

void Petrov::setSeqs()
{
	seqs.resize(5);
	for (auto &it : seqs) it.resize(params.size());
	seqs[0] = rule1();
	seqs[1] = rule2();
	seqs[2] = rule3();
	seqs[3] = rule4();

	// SPZ time
	std::random_device rd;
	std::mt19937 g(rd());
	std::vector<int> order(data.size(), 0);
	for (int i = 0; i < order.size(); i++) order[i] = i;
	std::shuffle(order.begin(), order.end(), g);

	seqs[4] = order;
}

void Petrov::setSeq(int seq) {
	if (seq >= -1 && seq <= 3) {
		int numDetails = data.size();
		order = std::vector<int>(numDetails, 0);
		if (seq == -1) {
			for (int i = 0; i < numDetails; i++) {
				order[i] = i;
			}
		}
		else order = seqs[seq];
		
		resetFinishTime();
		resetIdleTime();
	}
}

void Petrov::setSeq(std::vector<int> order) {
	this->order = order;
	resetFinishTime();
	resetIdleTime();
}

int Petrov::getMachineIdleTime()
{
	int	numDetails = data.size();
	int numMachines = data[0].size();
	int totalTime = 0;
	for (int j = 0; j < numMachines; j++) {
		int totalJTime = 0;
		for (int i = 0; i < numDetails; i++) {
			totalJTime += data[i][j];
		}
		int finishTimeId = numDetails - 1;

		while (data[order[finishTimeId]][j] == 0) finishTimeId--;

		int machineTime = finishTime[finishTimeId][j] - totalJTime;
		totalTime += machineTime;
	}

	return totalTime;
}

int Petrov::getWaitTime() {
	int	numDetails = data.size();
	int numMachines = data[0].size();

	int waitTime = 0;
	for (int i = 0; i < numDetails; i++) {
		int totalITime = 0;
		for (int j = 0; j < numMachines; j++) {
			totalITime += data[i][j];
		}
		int finishTimeId = numMachines - 1;
		while (data[i][finishTimeId] == 0) finishTimeId--;
		int detailTime = finishTime[i][finishTimeId] - totalITime;
		waitTime += detailTime;
	}
	return waitTime;
}

int Petrov::getFinishTime()
{
	return finishTime[data[0].size() - 1][data.size() - 1];
}

void Petrov::resetIdleTime()
{
	int	numDetails = data.size();
	int numMachines = data[0].size();
	// IDLE TIME
	idleTime = std::vector<std::vector<int>>(numDetails, std::vector<int>(numMachines, 0));
	for (int i = 0; i < numMachines; i++) {
		for (int j = 0; j < numDetails; j++) {
			int detailID = order[j];
			int lastDetail = 0;
			if (j > 0) lastDetail = finishTime[j - 1][i];
			idleTime[i][j] = finishTime[j][i] - lastDetail - data[detailID][i];
		}
	}
}

void Petrov::resetFinishTime()
{
	int	numDetails = data.size();
	int numMachines = data[0].size();
	// FINISH TIME
	finishTime = std::vector<std::vector<int>>(numDetails, std::vector<int>(numMachines, 0));
	for (int i = 0; i < numDetails; i++) {
		for (int j = 0; j < numMachines; j++) {
			int detailID = order[i];
			int processingTime = data[detailID][j];
			int temp = 0;
			if (i == 0 && j > 0) temp = finishTime[i][j - 1];
			else if (i > 0 && j == 0) temp = finishTime[i - 1][j];
			else if (i > 0 && j > 0) temp = std::max(finishTime[i][j - 1], finishTime[i - 1][j]);
			finishTime[i][j] = processingTime + temp;
		}
	}
}

Petrov::Petrov(const char* filename)
{
	ReadFile(filename);
	setParams();
	setSeqs();
	setSeq(-1);
}

int Petrov::getIdleTime(int i, int j)
{
	return idleTime.at(i).at(j);
}

int Petrov::getOrderID(int i)
{
	return order.at(i);
}
