import os
import sys

COLOR_GREEN = "\033[1;32m"
COLOR_BLACK = "\033[0m"


def executeCppCode(filename: str, CXX="g++"):
    filePath = current_path + "/codes/cpp/{}.cpp".format(filename)
    if os.path.isfile(filePath) is False:
        print("[!] File: {} not exist, please check the path.".format(filePath))
        exit(0)
    toExecuteCommand = "{} -g -o bin/test -fsanitize=address -Icodes/include {}".format(
        CXX,
        filePath)
    print(COLOR_GREEN + "[+] Start compiling cpp files: " +
          COLOR_BLACK + toExecuteCommand)
    val = os.system(toExecuteCommand)
    if val != 0:
        print("[?] Some errors occurred, exit.")
        exit(val)
    print(COLOR_GREEN + "[+] Start executing: " + COLOR_BLACK + "./bin/test")
    os.system("./bin/test")
    print(COLOR_GREEN + "[+] Execution finished: " + COLOR_BLACK + "rm ./bin/test")
    os.system("rm ./bin/test")


def executeRustCode(filename):
    pass


def executeCode(language: str, filename: str):
    language = language.lower()
    if language == "cpp":
        executeCppCode(filename)
    elif language == "py" or language == "python":
        pass
    elif language == "rs" or language == "rust":
        executeRustCode(filename)
    else:
        print("[!] Language not support!")
        exit(0)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(
            "[!] Arguments less than 2!\n\
[-] Usage: python run.py <language> <problem_i> # (without suffix)")
        exit(0)
    current_path = os.getcwd()
    print(COLOR_GREEN + "[+] Current working PATH: " +
          COLOR_BLACK + current_path)
    language = sys.argv[1]
    filename = sys.argv[2]
    executeCode(language, filename)
