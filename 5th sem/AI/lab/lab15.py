import numpy as np

class Perceptron:
    def __init__(self, learning_rate=0.1, max_iter=1000):
        self.learning_rate = learning_rate
        self.max_iter = max_iter
        self.weights = None
        self.bias = None

    def fit(self, X, y):
        n_samples, n_features = X.shape 
        self.weights = np.zeros(n_features)
        self.bias = 0

        for _ in range(self.max_iter):
            for xi, yi in zip(X, y):
                prediction = self.predict(xi)
                update = self.learning_rate * (yi - prediction)
                self.weights += update * xi
                self.bias += update

    def predict(self, X):
        linear_model = np.dot(X, self.weights) + self.bias
        y_predicted = np.where(linear_model >= 0, 1, 0)
        return y_predicted

# AND Gate
X_and = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y_and = np.array([0, 0, 0, 1])

perceptron_and = Perceptron()
perceptron_and.fit(X_and, y_and)

print("AND Gate:")
print("Weights:", perceptron_and.weights)
print("Bias:", perceptron_and.bias)

# OR Gate
X_or = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y_or = np.array([0, 1, 1, 1])

perceptron_or = Perceptron()
perceptron_or.fit(X_or, y_or)

print("\nOR Gate:")
print("Weights:", perceptron_or.weights)
print("Bias:", perceptron_or.bias)