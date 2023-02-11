import numpy as np
lcsString = ""


def getLcsString(lcsTable, str1, i, j):
    """A recursive function to get the longest common subsequence string from the computed LCS table.
    As the elements in the LCS are encountered in the reverse order, recursion gives us the lcs string in the proper, forward order.

    Args:
        lcsTable (numpy.ndarray): LCS Table with computed values for LCS string length
        str1 (string): first string given by the user (target string)
        i (integer): row index in the LCS table (initially at length of the str1)
        j (integer): column index in the LCS table (initially at length of the str2)
    """

    if i == 0 or j == 0:  # reached the top column or row of the LCS table, return back
        return
    # It's a case of when str1[i-1] == str2[j-1], part of lcs string
    if (lcsTable[i, j] != lcsTable[i, j-1]) and (lcsTable[i, j] != lcsTable[i-1, j]):
        # recurse through the top left column relative to element at index [i, j]
        getLcsString(lcsTable, str1, i-1, j-1)
        global lcsString
        # once it returns, the character will be present in the lcs string, so append it
        lcsString += str1[i-1]
    # elenment [i, j] is equal to top element [i-1, j]
    elif lcsTable[i, j] == lcsTable[i-1, j]:
        getLcsString(lcsTable, str1, i-1, j)
    else:
        # element [i, j] is equal to the left element [i, j-1]
        getLcsString(lcsTable, str1, i, j-1)


def longestCommonSubsequence(str1, str2):
    """This is a function that returns the length of the longest common subsequence between the two strings given by the user.
    It employs the use of Dynamic Programming to solve the problem efficiently.

    Args:
        str1 (string): The first string given by the user
        str2 (string): The second string given by the user

    Returns:
        integer: The length of the longest common subsequence
    """

    len1 = len(str1) + 1
    len2 = len(str2) + 1

    """
    Create a numpy array of shape (len1, len2) which will be our LCS Table
    Initialize the contents of the LCS Table to zero using the np.zeros() function
    The entries of the LCS Table will be computed in row-major order
    """
    lcsTable = np.zeros(shape=(len1, len2)).astype(int)
    
    # lcsTable = [[0]*len2 for i in range(len1)] for sites that don't support the utilization of numpy library
    # indexing will be lcsTable[i][j] rather than lcsTable[i, j]

    """
    The outer iteration starts at 1 till len1 is reached
    Each character of str1 will be compared
    """
    for i in range(1, len1):
        """
        The inner iteration starts at 1 till len2 is reached
        Each character of str2 will be compared
        """
        for j in range(1, len2):
            # if the character in str1 matches the character in str2, increment the element at [i-1, j-1] indices of the LCS Table by 1
            if str1[i - 1] == str2[j - 1]:
                lcsTable[i, j] = lcsTable[i-1, j-1] + 1
            # Otherwise, consider the max between the element at top of the index and to the left of the LCS Table relative to [i, j].
            else:
                lcsTable[i, j] = max(lcsTable[i, j-1], lcsTable[i-1, j])

    global lcsString
    lcsString = ""
    getLcsString(lcsTable, str1, len1-1, len2-1)

    # return the length of the longest common subsequence found at the last index of the LCS Table
    return lcsString, lcsTable[len1-1, len2-1]


def main():
    str1 = input("Enter the first string:")
    str2 = input("Enter the second string:")
    lcsString, lcsLength = longestCommonSubsequence(str1, str2)
    print("The longest common subsequence of string {} and string {} is {} and its length is {} .".format(
        str1, str2, lcsString, lcsLength))


if __name__ == '__main__':
    main()

"""

Sample Input1 -
Enter the first string: abcda
Enter the second string: bdabac

Sample Output1 -
The longest common subsequence of string abcda and string bdabac is abc and its length is 3 .

Sample Input2 -
Enter the first string: abcbdab
Enter the second string: bdcaba

Sample Output2 -
The longest common subsequence of string abcbdab and string bdcaba is bcba and its length is 4 .

LCS-Length function
    Time Complexity - O(mn) as each table entry will take O(1)
    Space Complexity - O(mn)

LCS-String function
    Time Complexity - O(m + n) as at least one of i and j is decremented at each stage of the recursion process.
    Space Complexity - O(mn)
"""
