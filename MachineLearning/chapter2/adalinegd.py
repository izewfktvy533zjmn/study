#!/usr/bin/env python3
from perceptron import Perceptron
import numpy as np


class AdalineGD(Perceptron):
	def fit(self, X, y):
		self.w_ = np.zeros(1 + X.shape[1])
		self.cost_ = []

		for _ in range(self.n_iter):
			output = self.activation(X)
			print(output)
			errors = y - output
			self.w_[1:] += self.eta * X.T.dot(errors)
			self.w_[0] += self.eta * errors.sum()
			cost = (errors**2).sum() / 2.0
			self.cost_.append(cost)

		return self


	def activation(self, X):
		return self.net_input(X)


	def predict(self, X):
		return np.where(self.activation(X) >= 0.0, 1, -1)

