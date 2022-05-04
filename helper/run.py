import os
import sys

COLOR_GREEN = "\033[1;32m"
COLOR_ORIGIN = "\033[0m"

def print_green(green_log, origin_log):
    print(COLOR_GREEN + green_log + COLOR_ORIGIN + origin_log)

def executeCppCode(filename: str, CXX="g++"):
    filePath = current_path + "/codes/cpp/{}.cpp".format(filename)
    if os.path.isfile(filePath) is False:
        print("[!] File: {} not exist, please check the path.".format(filePath))
        exit(0)
    toExecuteCommand = "{} -g -o bin/test -std=c++17 -fsanitize=address -Icodes/include {}".format(
        CXX,
        filePath)
    print_green("[+] Start compiling cpp files: ", toExecuteCommand)
    val = os.system(toExecuteCommand)
    if val != 0:
        print("[?] Some errors occurred, exit.")
        exit(val)
    print_green("[+] Execution start: ", "./bin/test")
    os.system("./bin/test")
    print_green("[+] Execution finish: ", "rm ./bin/test")
    os.system("rm ./bin/test")


def executeRustCode(filename: str):
    os.chdir("./codes/rust/")
    print_green("[+] Working dir: ", os.getcwd())
    os.system("RUST_BACKTRACE=1 cargo test test_{}".format(filename))

def executePythonCode(filename: str):
    os.chdir("./codes/python/")
    print_green("[+] Working dir: ", os.getcwd())
    os.system("python {}.py".format(filename))

def executeCode(language: str, filename: str):
    language = language.lower()
    if language == "cpp" or language == "c++":
        executeCppCode(filename)
    elif language == "py" or language == "python":
        executePythonCode(filename)
    elif language == "rs" or language == "rust":
        executeRustCode(filename)
    else:
        print("[!] Language not support!")
        exit(0)


if __name__ == '__main__':
    os.chdir("../")
    if len(sys.argv) < 3:
        print(
            "[!] Arguments less than 2!\n\
[-] Usage: python run.py <language> <problem_i> # (without suffix)")
        exit(0)
    current_path = os.getcwd()
    print_green("[+] Current working PATH: ", current_path)
    language = sys.argv[1]
    filename = sys.argv[2]
    executeCode(language, filename)
