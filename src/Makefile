CC 						= gcc -std=c11
OS 						= $(shell uname)

# flags #
CFLAG 					= -Wall -Werror -Wextra
GCOV 					= --coverage
CLEAN					= rm -rf
TEXI2DVI 				= makeinfo --html

# libraries #
ifeq ($(OS), Linux)
	CHECK_LIBS 			= -lcheck -lpthread -lrt -lm -lsubunit
	LEAKS				= CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TEST_NAME)
	OPEN 				= xdg-open
	APP					= 3DViewerV1
else
	CHECK_LIBS 			= -lcheck -lm -lpthread
	LEAKS				= CK_FORK=no leaks --atExit -- ./$(TEST_NAME)
	OPEN 				= open
	APP					= 3DViewerV1.app
endif

# names and extensions #
NAME 					= 3DViewer_v1_0
LIB 					= $(NAME).a
#  #
TEST_NAME				= $(NAME)_tests
TEST_SOURCE 			= $(TEST_NAME).c
TEST_OBJECT 			= $(TEST_SOURCE:%.c=%.o)
TEST_DIR				= .
BUILD_DIR 				= ../build
DOCUMENT_DIR			= ../documentation
MAIN_DIR				= ./3DViewer_v1_0
DIST_NAME 				= $(NAME)-1.0

TEST_CHECK_DIR			= ./tests
INC 					= includes

SOURCES 				= 3DViewer_v1_0/functions/reading_obj_file.c 3DViewer_v1_0/functions/affine_transformations.c
SRC_DIR					= ./functions
HEADERS 				= *.h
H_DIR					= .
OBJECTS 				= reading_obj_file.o affine_transformations.o

# targets #
all: install

$(LIB):
	$(CC) $(CFLAG) -c $(SOURCES) 
	ar rcs $(LIB) $(OBJECTS)
	ranlib  $(LIB)
	cp $(LIB) lib$(LIB)
	$(CLEAN) $(OBJECTS)

install: uninstall dvi 
	qmake CONFIG+=release -o $(BUILD_DIR)/Makefile 3DViewer_v1_0/3DViewer_v1_0.pro
	-cd $(BUILD_DIR); make
	-cd $(BUILD_DIR); make clean
	$(CLEAN) $(BUILD_DIR)/Makefile
	$(CLEAN) $(BUILD_DIR)/.qmake.stash
	$(CLEAN) $(BUILD_DIR)/qmake_qmake_qm_files.qrc
	$(CLEAN) $(BUILD_DIR)/.qm

uninstall: clean
	$(CLEAN) $(BUILD_DIR)

dvi:
	makeinfo -o $(DOCUMENT_DIR) --html --no-warn --no-validate --force documentation.texi

dist:
	cd ..; $(CLEAN) $(DIST_NAME).tar.gz
	$(CLEAN) ../$(DIST_NAME)
	cd ..; cp -r src $(DIST_NAME)
	cd ..; tar -cvf $(DIST_NAME).tar.gz $(DIST_NAME)
	$(CLEAN) ../$(DIST_NAME)

# targets for tests   #
tests: clean $(LIB) testgen
	$(CC) $(CFLAG) $(TEST_DIR)/$(TEST_SOURCE) $(LIB) -o $(TEST_NAME) $(CHECK_LIBS)
	$(CLEAN) $(TEST_SOURCE)
	./$(TEST_NAME)
	$(CLEAN) *.a *.out

gcov_report: testrm testgen
	gcc -fprofile-arcs -ftest-coverage $(GCOV) $(SOURCES) $(TEST_DIR)/$(TEST_SOURCE) $(CHECK_LIBS) -o coverage_$(NAME)
	-./coverage_$(NAME)
	lcov -t "$(TEST_NAME)" -o $(TEST_NAME).info -c -d .
	genhtml -o report $(TEST_NAME).info
	-$(OPEN) report/index.html
	$(CLEAN) *.gcda *.gcno *.gz *.a *.out *.info coverage_$(NAME) $(TEST_SOURCE)

# assembly #
testgen:
	checkmk clean_mode=1 $(TEST_CHECK_DIR)/$(INC) $(TEST_CHECK_DIR)/*.check > $(TEST_SOURCE)

testrm:
	$(CLEAN) $(TEST_SOURCE)

clean: testrm
	$(CLEAN) *.o *.a *.gcno *.gcda *.info *.out coverage ../documentation report $(TEST_NAME) gcov_report_$(NAME) .DS_Store tests/.DS_Store build-3DViewer_v1_0-Desktop-Debug
	$(CLEAN) ../$(DIST_NAME).tar.gz ../$(DIST_NAME) .clang-format
	#$(CLEAN) $(BUILD_DIR)

rebuild: clean all

open_report:
	-$(OPEN) report/index.html

open_dvi:
	-$(OPEN) $(DOCUMENT_DIR)/index.html

# for debug #
check: clang cppcheck leaks clean

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n $(NAME)/functions/*.c
	clang-format -n $(NAME)/functions/*.h
	clang-format -n $(NAME)/*.h
	clang-format -n $(NAME)/*.cpp
	rm .clang-format

cppcheck:
	cppcheck --enable=all --suppress=missingInclude --check-config  $(NAME)/*.h $(NAME)/*/*.h $(NAME)/*/*.c $(NAME)/*.cpp

leaks: tests
	$(LEAKS)

.PHONY: all clean rebuild tests install uninstall leaks cppcheck clang check openr testrm testgen gcov_report opendvi dvi dist
