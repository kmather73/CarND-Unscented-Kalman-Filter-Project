#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  VectorXd error(4);
	size_t n = min(estimations.size(), ground_truth.size());
	for(size_t i=0; i < n; ++i){
		VectorXd residual = estimations[i] - ground_truth[i];

		//coefficient-wise multiplication
		residual = residual.array()*residual.array();
		error += residual;
	}

	error = error/n;
	error = error.array().sqrt();

	return error;
}