import numpy as np

class KNN:
    def __init__(self, k_neigh, weighted=False, p=2):

        self.weighted = weighted
        self.k_neigh = k_neigh
        self.p = p

    def fit(self, data, target):
        self.data = data
        self.target = target.astype(np.int64)

        return self

    def find_distance(self, x):
        distances = []
        for point in x:
            diff = np.abs(self.data.T - np.array(point).reshape(x.shape[1], 1))**self.p
            dot = np.sum(diff, axis = 0)**(1/self.p)
            distances.append(list(dot))
        
        return np.array(distances)

    def k_neighbours(self, x):
        neigh_dists = []
        idx_of_neigh = []

        distances = self.find_distance(x)
        for d in range(len(distances)):
            neigh_dists.append([])
            idx_of_neigh.append([])
            idx = np.argsort(distances[d])
            for k in range(self.k_neigh):
                neigh_dists[d].append(distances[d][idx[k]])
                idx_of_neigh[d].append(idx[k])

        return [np.array(neigh_dists), np.array(idx_of_neigh)]

    def predict(self, x):
        res = []
        e = 0.00000001
        if(self.weighted):            
            dists, idx = self.k_neighbours(x)
            B = 1/(dists+e)
            for d in range(len(B)):
                votes = {k:0 for k in set(self.target)}
                for i in range(len(B[d])):
                    votes[self.target[idx[d][i]]]+=B[d][i]
                res.append(max(votes, key= lambda x: votes[x]))


        else:
            _, idx = self.k_neighbours(x)
            for i in idx:
                votes = {k:0 for k in set(self.target)}
                for j in i:
                    votes[self.target[j]]+=1
                res.append(max(votes, key= lambda x: votes[x]))

        return np.array(res)

    def evaluate(self, x, y):
        acc = np.sum(np.array(y) == self.predict(x))/len(list(y))
        return acc*100
