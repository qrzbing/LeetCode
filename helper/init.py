import sys
import os
from language_template import cpp_solution_template, python_solution_template, rust_solution_template


def fileNotExists(filename: str) -> bool:
    if os.path.exists(filename):
        print("[+] File {} exists, exit!".format(filename))
        return False
    return True


def initRustCode(filename: str):
    solution_file_path = "./codes/rust/src/solutions/"
    mod_file_path = "./codes/rust/src/solutions/mod.rs"
    mod_flag = True
    with open(mod_file_path, "r") as f:
        lines = f.readlines()
        for line in lines:
            line = line.strip()
            if line[6:-1] == filename:
                print("[+] Mod {} exists, exit!".format(line))
                mod_flag = False
                break
    if mod_flag is True:
        with open(mod_file_path, "a") as f:
            f.write("mod s_{};\n".format(filename))
    ans_file_path = solution_file_path + "s_{}.rs".format(filename)
    if fileNotExists(ans_file_path) is True:
        with open(ans_file_path, "w") as f:
            f.write(rust_solution_template.format(filename))


def initCppCode(filename: str):
    ans_file_path = "./codes/cpp/{}.cpp".format(filename)
    if fileNotExists(ans_file_path) is True:
        with open(ans_file_path, "w") as f:
            f.write(cpp_solution_template)


def initPythonCode(filename: str):
    ans_file_path = "./codes/python/{}.py".format(filename)
    if fileNotExists(ans_file_path) is True:
        with open(ans_file_path, "w") as f:
            f.write(python_solution_template)


def initCode(language: str, filename: str):
    language = language.lower()
    if language == "rust":
        initRustCode(filename)
    elif language == "cpp":
        initCppCode(filename)
    elif language == "python" or language == "py":
        pass
    else:
        exit(0)


if __name__ == '__main__':
    # Usage: python init.py rust 1748
    os.chdir("../")
    language = sys.argv[1].lower()
    filename = sys.argv[2]
    initCode(language, filename)
