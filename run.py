import os
import sys

COLOR_GREEN = "\033[1;32m"
COLOR_BLACK = "\033[0m"

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(
            "[!] Arguments less than 2!\n[-] Usage: python run.py <language> <problem_i.suffix>")
        exit(0)
    current_path = os.getcwd()
    print(COLOR_GREEN + "[+] Current working PATH: " +
          COLOR_BLACK + current_path)
    language = sys.argv[1]
    filename = sys.argv[2]
    if language == "cpp":
        filePath = current_path + "/codes/cpp/{}.cpp".format(filename)
        if os.path.isfile(filePath) is False:
            print("[!] File: {} not exist, please check the path.".format(filePath))
            exit(0)
        toExecuteCommand = "g++ -g -o bin/test -fsanitize=address -Icodes/include {}".format(
            filePath)
        print(COLOR_GREEN + "[+] Start execute cpp files: " +
              COLOR_BLACK + toExecuteCommand)
        val = os.system(toExecuteCommand)
        if val != 0:
            print("[?] Some errors occurred, exit.")
            exit(val)
        os.system("./bin/test")
    elif language == "python":
        pass
    elif language == "rust":
        pass
    else:
        print("[!] Language not support!")
        exit(0)
