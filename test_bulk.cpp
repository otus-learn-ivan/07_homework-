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

#include <sys/types.h>
#include <dirent.h>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_bulk)


BOOST_AUTO_TEST_CASE(test_test)
{
  BOOST_CHECK(true == true);
}

std::vector<std::string> created_files_log(){
DIR *dir;
   struct dirent *ent;
   dir = opendir("."); // "." - текущая директория
   std::vector<std::string> log_files;

   if (dir != nullptr) {
       while ((ent = readdir(dir)) != nullptr) {
           if (ent->d_type == DT_REG && std::string(ent->d_name).find(".log") != std::string::npos) {
               log_files.push_back(ent->d_name); // Добавляем имя файла в вектор
           }
       }
       closedir(dir);
   } else {
       // Обработка ошибки
       std::cerr << "Ошибка открытия директории\n";
   }
   std::sort(log_files.begin(),log_files.end());
   return log_files;
}
std::vector<std::string>  set_suit_cmd( std::vector<std::string>& commands ){
    // Запускаем приложение bulk через popen
    FILE* pipe = popen("./bulk 3", "w");
    if (pipe == nullptr) {
        std::cerr << "Ошибка запуска процесса bulk\n";
        return std::vector<std::string>{};
    }

    // Отправляем команды с задержкой
    for (const auto& cmd : commands) {
        fprintf(pipe, "%s\n", cmd.c_str());
        std::cout << cmd << std::endl;
        sleep(1); // задержка в 1 секунду
    }

    // Закрываем поток для записи
    pclose(pipe);
    return created_files_log();
}


BOOST_AUTO_TEST_CASE(test_valid)
{
  std::cout <<"test_valid" << std::endl;
  // Формируем команды
  std::vector<std::string> suit_commands1 = {"cmd10", "cmd2", "cmd3","cmd4","cmd5","cmd6"};
  auto log_files = set_suit_cmd(suit_commands1);
  for (auto& files : log_files) {
      std::cout << files<<"\n";
  }
  //system("rm *.log");
}

BOOST_AUTO_TEST_SUITE_END()
