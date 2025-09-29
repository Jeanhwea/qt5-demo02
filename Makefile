dist:

setup:
	cmake -B build

dist:
	make -C build

format:
	find include -type f | xargs -I {} clang-format -i {}
	find source -type f | xargs -I {} clang-format -i {}
