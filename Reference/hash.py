import hashlib
import re
import sys
import os

def get_hash(text):
    text = re.sub(r'//.*', '', text)
    clean = re.sub(r'\s+', '', text).lower()
    return hashlib.md5(clean.encode()).hexdigest()[:6]

def process_cpp(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()

    output, code_buf, count, full_code = [], "", 0, ""
    for line in lines:
        if line.strip() and not line.strip().startswith(("//", "/*", "*")):
            code_buf += line
            full_code += line
            count += 1
            if count % 5 == 0:
                line = f"{line.rstrip()} // #{get_hash(code_buf)}\n"
                code_buf = ""
        output.append(line)

    with open(filename, 'w') as f:
        f.write(f"// Hash: {get_hash(full_code)}\n" + "".join(output))

if __name__ == "__main__":
    process_cpp(sys.argv[1])
