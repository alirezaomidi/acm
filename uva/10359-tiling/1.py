dp = []

def ways(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if dp[n] > 0:
        return dp[n]
    dp[n] = ways(n - 1) + 2 * ways(n - 2)
    return dp[n]

if __name__ == '__main__':
    while True:
        try:
            n = int(input())
        except EOFError:
            break

        dp = [0] * (2 * n + 1)
        print(ways(n))
