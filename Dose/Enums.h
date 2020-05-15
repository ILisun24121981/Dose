#ifndef ENUMS_H
#define ENUMS_H


namespace Lis {
    //

    enum Verification_result {
        Verification_problem,
        Login_is_not_correct,
        Password_is_not_correct,
        Verification_Passed
    };

    //Используется для формирования вектора содержащего настройки (Settings.h/cpp)
    //Порядок должен совпадать с порядком перечисления настроек в файле Settings.txt
    enum Setting_name {
        Logins_and_passports_file_folder,
        Common_reports_folder,
        Personal_reports_folder,
        Logs_file_folder
    };

    enum Updated_point{
        File_name,
        Time_date
    };
}

#endif // ENUMS_H
