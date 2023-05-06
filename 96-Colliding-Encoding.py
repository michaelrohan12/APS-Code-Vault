def main():
    n = int(input())
    for _ in range(n):
        flag = 1
        arr = list(input().strip().split())
        alphabet_dict = {}
        for i, letter in enumerate('ABCDEFGHIJKLMNOPQRSTUVWXYZ'):
            alphabet_dict[letter] = arr[i]
        m = int(input())
        cipher_list = []
        for _ in range(m):
            cipher = ""
            string = input()
            if flag:
                for char in string:
                    cipher += alphabet_dict[char]

                if cipher in cipher_list:
                    print("YES")
                    flag = 0
                else:
                    cipher_list.append(cipher)

        if flag:
            print("NO")


main()
