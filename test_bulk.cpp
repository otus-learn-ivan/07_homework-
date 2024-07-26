#define BOOST_TEST_MODULE test_bulk

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>


#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_bulk)


BOOST_AUTO_TEST_CASE(test_test)
{
  BOOST_CHECK(true == true);
}

void set_suit_cmd( std::vector<std::string>& commands ){
    // Запускаем приложение bulk через popen
    FILE* pipe = popen("./bulk 3", "w");
    if (pipe == nullptr) {
        std::cerr << "Ошибка запуска процесса bulk\n";
        return;
    }

    // Отправляем команды с задержкой
    for (const auto& cmd : commands) {
        fprintf(pipe, "%s\n", cmd.c_str());
        std::cout << cmd << std::endl;
        sleep(1); // задержка в 1 секунду
    }

    // Закрываем поток для записи
    pclose(pipe);
}


BOOST_AUTO_TEST_CASE(test_valid)
{
  std::cout <<"test_valid" << std::endl;
  // Формируем команды
  std::vector<std::string> suit_commands1 = {"cmd1", "cmd2", "cmd3"};
  set_suit_cmd(suit_commands1);

}

BOOST_AUTO_TEST_SUITE_END()
