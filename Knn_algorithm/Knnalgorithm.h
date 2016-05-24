/*
 * Knnalgorithm.h
 *
 *  Created on: May 23, 2016
 *      Author: marija
 */

#ifndef KNNALGORITHM_H_
#define KNNALGORITHM_H_

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <stdexcept>

class Knn_algorithm {
public:
	Knn_algorithm(const std::vector<std::vector<double>> & in,
				  const std::vector<std::vector<double>> & out,
				  int nn, double (*d)(const std::vector<double> &, const std::vector<double> &),
				  bool v=false)
		:inputs{in}, outputs{out}, k{nn}, distance_func{d}, vote{v}{}
	std::vector<double> operator()(const std::vector<double> & query_point);
	static constexpr double tolerance=1e-10;
private:
	const std::vector<std::vector<double>> inputs;
	const std::vector<std::vector<double>> outputs;
	int k;
	double (*distance_func)(const std::vector<double> &, const std::vector<double> &);
	bool vote;
	std::vector<std::pair<double, int>> calculate_distances(const std::vector<double> & query_point);
	std::vector<double> get_average(const std::vector<std::pair<double, int>> & knn);
	std::vector<double> find_most_common(const std::vector<std::pair<double, int>> & knn);
	bool check_database(const std::vector<double> & query_point, std::vector<double> &);
};

#endif /* KNNALGORITHM_H_ */
