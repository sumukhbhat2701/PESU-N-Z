import numpy as np


class HMM:
    """
    HMM model class
    Args:
        A: State transition matrix
        states: list of states
        emissions: list of observations
        B: Emmision probabilites
    """

    def __init__(self, A, states, emissions, pi, B):
        self.A = A
        self.B = B
        self.states = states
        self.emissions = emissions
        self.pi = pi
        self.N = len(states)
        self.M = len(emissions)
        self.make_states_dict()

    def make_states_dict(self):
        """
        Make dictionary mapping between states and indexes
        """
        self.states_dict = dict(zip(self.states, list(range(self.N))))
        self.emissions_dict = dict(
            zip(self.emissions, list(range(self.M))))

    def viterbi_algorithm(self, seq):
        """
        Function implementing the Viterbi algorithm
        Args:
            seq: Observation sequence (list of observations. must be in the emmissions dict)
        Returns:
            u: Porbability of the hidden state at time t given an obeservation sequence
            hidden_states_sequence: Most likely state sequence 
        """
        # nu = u and temperature = T
        # INitialize to 0
        u = np.zeros((len(seq), self.N))
        T = np.zeros((len(seq), self.N), dtype=int)

        # Initialize using initial probability
        for col in range(self.N):
            u[0, col] = self.pi[col] * self.B[col, self.emissions_dict[seq[0]]]
            T[0, col] = 0

        # Find the max ones for every seqeunce, for every N and update
        for s in range(1, len(seq)):
            for n in range(self.N):
                u_max = -1
                max_ = -1
                for i in range(self.N):
                    if u[s - 1, i] * self.A[i, n] * self.B[n, self.emissions_dict[seq[s]]] > u_max:
                        u_max, max_ = u[s - 1, i] * self.A[i, n] * self.B[n, self.emissions_dict[seq[s]]], i
                u[s, n] = u_max
                T[s, n] = max_

        # Find the final max value
        u_max, max_ = -1, -1
        for n in range(self.N):
            if u[len(seq) - 1, n] > u_max:
                u_max = u[len(seq) - 1, n]
                max_ = n

        # Return the most likely state sequence
        ans = []
        ans.append(max_)
        for s in range(len(seq) - 1, 0, -1):
            ans.append(T[s, ans[-1]])

        rev_dict = {self.states_dict[i]: i for i in self.states_dict}
        res = [rev_dict[i] for i in ans[-1::-1]]
        return res