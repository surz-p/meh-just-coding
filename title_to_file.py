import sys

title_name = None

if len(sys.argv) == 1:
	title_name = input('Enter question title as is: ')
else:
	title_name = sys.argv[1]

title_name = title_name.replace('. ', '_').replace(' ', '_').lower()

cpp_file = f"{title_name}.cpp"
py_file = f"{title_name}.py"

open(cpp_file, 'a').close()
open(py_file, 'a').close()

print(f"{cpp_file}, {py_file} created")

