#!/usr/bin/env python3
import sys
import os

current_path = os.path.dirname(__file__)
template_path = "{}/{}".format(current_path, "helper")


def fileNotExists(filename: str) -> bool:
    if os.path.exists(filename):
        print("[+] File {} exists, exit!".format(filename))
        return False
    return True


def initPythonCode(filename: str):
    ans_file_path = "./{}.py".format(filename)
    template_python = "{}/{}".format(template_path, "python.py")
    with open (template_python, "r") as f:
        data_python = f.read()
        with open (ans_file_path, "w") as w:
            w.write(data_python)


def initCode(language: str, filename: str):
    language = language.lower()
    if language not in ["rust", "cpp", "python", "py", "c"]:
        print("[!] Invalid language!")
        help_func()
    if language == "rust":
        os.chdir("./rust")
        initRustCode(filename)
    elif language == "cpp":
        os.chdir("./cpp")
        initCppCode(filename)
    elif language == "python" or language == "py":
        os.chdir("./python")
        initPythonCode(filename)
    else:
        exit(0)


def help_func():
    print(
        """Usage:
python init.py <leetcode|luogu|...> <python|cpp|rust> <problem id>
""")
    exit(0)


def main():
    print(len(sys.argv))
    if len(sys.argv) < 4:
        print("[!] Invalid args number!")
        help_func()
    website = sys.argv[1]
    language = sys.argv[2].lower()
    problem_id = sys.argv[3]
    if website not in ["leetcode", "luogu"]:
        print("[!] Invalid OJ!")
        help_func()
    os.chdir("{}/{}".format(current_path, website))
    initCode(language, problem_id)


if __name__ == "__main__":
    main()
