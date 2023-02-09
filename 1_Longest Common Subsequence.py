# str1 = "abcda"
# str2 = "bdabac"

import numpy as np


def longestCommonSubsequence(str1, str2):
    """This is a function that returns the length of the longest common subsequence between the two strings given by the user.
    It employs the use of Dynamic Programming to solve the problem efficiently.

    Args:
        str1 (string): The first string given by the user
        str2 (string): The second string given by the user

    Returns:
        integer: The length of the longest common subsequence
    """

    len1 = len(str1)
    len2 = len(str2)

    """
    Create a numpy array of shape (len1, len2) which will be our LCS Table
    Initialize the contents of the LCS Table to zero using the np.zeros() function
    The entries of the LCS Table will be computed in row-major order
    """
    lcsTable = np.zeros(shape=(len1 + 1, len2 + 1)).astype(int)

    """
    The outer iteration starts at 1 till len1 is reached
    Each character of str1 will be compared
    """
    for i in range(1, len1 + 1):
        """
        The inner iteration starts at 1 till len2 is reached
        Each character of str2 will be compared
        """
        for j in range(1, len2 + 1):
            # if the character in str1 matches the character in str2, increment the element at [i-1, j-1] indices of the LCS Table by 1
            if str1[i - 1] == str2[j - 1]:
                lcsTable[i, j] = lcsTable[i-1, j-1] + 1
            # Otherwise, consider the max between the element at top of the index and to the left of the LCS Table relative to [i, j].
            else:
                lcsTable[i, j] = max(lcsTable[i, j-1], lcsTable[i-1, j])

    # return the length of the longest common subsequence found at the last index of the LCS Table
    return lcsTable[len1, len2]


def main():
    str1 = input("Enter the first string:")
    str2 = input("Enter the second string:")
    lcsLength = longestCommonSubsequence(str1, str2)
    print("The length of the longest common subsequence is {} .".format(lcsLength))


if __name__ == '__main__':
    main()

"""

Sample Input1 -
Enter the first string: abcda
Enter the second string: bdabac

Sample Output1 -
The length of the longest common subsequence is 3.

Sample Input2 -
Enter the first string: abcbdab
Enter the second string: bdcaba

Sample Output2 -
The length of the longest common subsequence is 4.

Time Complexity - O(mn) as each table entry will take O(1)
Space Complexity - O(mn)
"""
