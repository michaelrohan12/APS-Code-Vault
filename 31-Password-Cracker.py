import sys
sys.setrecursionlimit(5000)
testcases = int(input())
memo = {}


def solve(attempt, passwords, output, strLoc):
    global memo
    if strLoc not in memo and strLoc != len(attempt):
        fail_path = True
        for password in passwords:
            if len(password) <= (len(attempt) - strLoc):
                if password == (attempt[strLoc:(strLoc+len(password))]):
                    output.append(password)
                    output = solve(attempt, passwords, output,
                                   strLoc + len(password))
                    if len("".join(output)) == len(attempt):
                        fail_path = False
                        break
        if fail_path:
            memo[strLoc] = True

    if strLoc in memo:
        output = output[:-1]

    return output


for i in range(testcases):
    memo = {}
    input()
    passwords = input().split(" ")
    attempt = input()
    output = solve(attempt, passwords, [], 0)
    if len("".join(output)) != len(attempt):
        print("WRONG PASSWORD")
    else:
        print(" ".join(output))
