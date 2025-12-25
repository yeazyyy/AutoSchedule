#include "database.h"
#include <QFile>

database::database() {
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./schedule.db");
    bool open = db.open();
    query = new QSqlQuery(db);

    query->exec("CREATE TABLE IF NOT EXISTS Coaches("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "fullname TEXT NOT NULL)");

    query->exec("CREATE TABLE IF NOT EXISTS Group_types("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL UNIQUE,"
                "hours INT NOT NULL CHECK(hours>0))");

    query->exec("INSERT INTO Group_types VALUES"
                "(1, 'НП-1', 6),"
                "(2, 'НП-2', 6),"
                "(3, 'НП-3', 6),"
                "(4, 'УТГ-1', 9),"
                "(5, 'УТГ-2', 12),"
                "(6, 'УТГ-3', 15),"
                "(7, 'УТГ-4', 18),"
                "(8, 'УТГ-5', 18),"
                "(9, 'УТГ-6', 18),"
                "(10, 'УТГ-7', 18),"
                "(11, 'СПС-УТГ', 21),"
                "(12, 'СПС-1', 21),"
                "(13, 'СПС-2', 23),"
                "(14, 'СПС-3', 26),"
                "(15, 'СПС-4', 26),"
                "(16, 'СПС-5', 26),"
                "(17, 'СПС-6', 26),"
                "(18, 'ВСМ-СПС', 30),"
                "(19, 'ВСМ', 30),"
                "(20, 'ПГ', 2),"
                "(21, 'Внешние', 1),"
                "(22, 'НП-1 ПГ', 6),"
                "(23, 'УОР', 1)");

    query->exec("CREATE TABLE IF NOT EXISTS Ranks("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL UNIQUE)");

    query->exec("INSERT INTO Ranks VALUES"
                "(1, '2юн'),"
                "(2, '1юн'),"
                "(3, '3'),"
                "(4, '2'),"
                "(5, '1'),"
                "(6, 'КМС'),"
                "(7, 'МС'),"
                "(8, 'МСМК'),"
                "(9, 'ЗМС')");

    query->exec("CREATE TABLE IF NOT EXISTS Place("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL UNIQUE,"
                "start_ofset INT NOT NULL,"
                "amount_of_starts INT NOT NULL,"
                "amount_of_rows INT NOT NULL,"
                "schedule_header TEXT NOT NULL DEFAULT '')");

    query->exec("INSERT INTO Place (name,start_ofset,amount_of_starts,amount_of_rows,schedule_header) VALUES"
                "('Бассейн 50м', 0, 22, 10,     'Расписание занятий в учебно-тренировочном бассейне (50 метров)'),"
                "('Бассейн 50м (2x25)', 0, 22, 20,     'Расписание занятий в учебно-тренировочном бассейне (50 метров)'),"
                "('Бассейн 25м', 2, 19, 4,      'Расписание занятий в физкультурно-оздоровительном бассейне (25 метров)'),"
                "('Зал №205', 1, 20, 5,         'Расписание учебно-тренировочных занятий в Специализированном зале прыжков в воду №205'),"
                "('Зал №206', 1, 20, 3,         'Расписание учебно-тренировочных занятий в Тренажёрном зале \"Orange\" №206'),"
                "('Зал №209', 1, 20, 3,         'Расписание учебно-тренировочных занятий в Игровом зале №209'),"
                "('Зал №312', 1, 20, 3,         'Расписание учебно-тренировочных занятий в зале Сухого плавание №312'),"
                "('Зал №314', 1, 20, 3,         'Расписание учебно-тренировочных занятий в зале Хореографии №314'),"
                "('Зал №317', 1, 20, 3,         'Расписание учебно-тренировочных занятий в зале Сухого плавание №317'),"
                "('Бассейн Малютка', 4, 17, 1,  'Расписание занятий в бассейне Малютка'),"
                "('Прыжковый бассейн', 1, 20, 5,'Расписание учебно-тренировочных занятий в Прыжковом бассейне')");

    query->exec("CREATE TABLE IF NOT EXISTS Branches("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL UNIQUE,"
                "color INT NOT NULL)");

    query->exec("INSERT INTO Branches VALUES"
                "(1, 'Водное поло', '#606060'),"
                "(2, 'Плавание', '#3399FF'),"
                "(3, 'Инваспорт плавание', '#A0A0A0'),"
                "(4, 'Синхронное плавание', '#FFB266'),"
                "(5, 'Прыжки в воду', '#0000FF')");

    query->exec("CREATE TABLE IF NOT EXISTS Groups("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "group_type_id INT NOT NULL,"
                "date_of_formation TEXT,"
                "coach_id INT,"
                "branch_id INT,"
                "hierarchy INT,"
                "FOREIGN KEY(coach_id) REFERENCES Coaches(id),"
                "FOREIGN KEY(branch_id) REFERENCES Branches(id),"
                "FOREIGN KEY(group_type_id) REFERENCES Group_types(id))");

    query->exec("CREATE TABLE IF NOT EXISTS Organizations("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL,"
                "group_id INT NOT NULL,"
                "FOREIGN KEY(group_id) REFERENCES Groups(id))");

    // query->exec("CREATE TABLE IF NOT EXISTS Replacements("
    //             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    //             "coach_id INT NOT NULL,"
    //             "group_id INT NOT NULL,"
    //             "date_start TEXT NOT NULL,"
    //             "date_end TEXT NOT NULL,"
    //             "FOREIGN KEY(coach_id) REFERENCES Coaches(id),"
    //             "FOREIGN KEY(group_id) REFERENCES Groups(id))");

    query->exec("CREATE TABLE IF NOT EXISTS Start_time("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "time TEXT NOT NULL)");

    query->exec("INSERT INTO Start_time VALUES"
                "(1, '6:00'),"
                "(2, '6:45'),"
                "(3, '7:30'),"
                "(4, '8:15'),"
                "(5, '9:00'),"
                "(6, '9:45'),"
                "(7, '10:30'),"
                "(8, '11:15'),"
                "(9, '12:00'),"
                "(10, '12:45'),"
                "(11, '13:30'),"
                "(12, '14:15'),"
                "(13, '15:00'),"
                "(14, '15:45'),"
                "(15, '16:30'),"
                "(16, '17:15'),"
                "(17, '18:00'),"
                "(18, '18:45'),"
                "(19, '19:30'),"
                "(20, '20:15'),"
                "(21, '21:00'),"
                "(22, '21:45')");

    // query->exec("CREATE TABLE IF NOT EXISTS Settings("
    //             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    //             "start_ofset_50 INT NOT NULL,"
    //             "amount_of_starts_50 INT NOT NULL,"
    //             "start_ofset_25 INT NOT NULL,"
    //             "amount_of_starts_25 INT NOT NULL,"
    //                 "start_ofset_jumping INT NOT NULL,"
    //                 "amount_of_starts_jumping INT NOT NULL,"
    //                 "start_ofset_baby INT NOT NULL,"
    //                 "amount_of_starts_baby INT NOT NULL,"
    //                     "start_ofset_205 INT NOT NULL,"
    //                     "amount_of_starts_205 INT NOT NULL,"
    //                     "start_ofset_206 INT NOT NULL,"
    //                     "amount_of_starts_206 INT NOT NULL,"
    //                     "start_ofset_209 INT NOT NULL,"
    //                     "amount_of_starts_209 INT NOT NULL,"
    //                         "start_ofset_312 INT NOT NULL,"
    //                         "amount_of_starts_312 INT NOT NULL,"
    //                         "start_ofset_314 INT NOT NULL,"
    //                         "amount_of_starts_314 INT NOT NULL,"
    //                         "start_ofset_317 INT NOT NULL,"
    //                         "amount_of_starts_317 INT NOT NULL)");

    // query->exec("INSERT INTO Settings VALUES"
    //             "(1,"
    //             "0, 20, 1, 19, 0, 20, 3, 17,"
    //             "0, 20, 0, 20, 0, 20,"
    //             "0, 20, 0, 20, 0, 20)");

    query->exec("CREATE TABLE IF NOT EXISTS Trainings("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "day INT NOT NULL,"
                "time_id INT NOT NULL,"
                "group_id INT NOT NULL,"
                "amount_of_tracks INT,"
                "place_id INT NOT NULL,"
                "commentary TEXT DEFAULT '',"
                "FOREIGN KEY(time_id) REFERENCES Start_time(id),"
                "FOREIGN KEY(group_id) REFERENCES Groups(id) ON DELETE CASCADE,"
                "FOREIGN KEY(place_id) REFERENCES Place(id) ON DELETE CASCADE)");

    query->exec("CREATE TABLE IF NOT EXISTS Pupils("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "fullname TEXT NOT NULL,"
                "rank_id INT NOT NULL,"
                "group_id INT NOT NULL,"
                "FOREIGN KEY(rank_id) REFERENCES Ranks(id),"
                "FOREIGN KEY(group_id) REFERENCES Groups(id))");

    query->exec("CREATE TABLE IF NOT EXISTS Events("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "name TEXT NOT NULL)");

    query->exec("INSERT INTO Events VALUES"
                "(1, 'Санитарный час'),"
                "(2, 'Санитарный день'),"
                "(3, 'Чемпионат Республики Беларусь'),"
                "(4, 'Кубок Республики Беларусь'),"
                "(5, 'Первенство Республики Беларусь')");

    query->exec("CREATE TABLE IF NOT EXISTS Current_events("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "day INT NOT NULL,"
                "time_id INT NOT NULL,"
                "event_id INT NOT NULL,"
                "place_id INT NOT NULL,"
                "FOREIGN KEY(time_id) REFERENCES Start_time(id),"
                "FOREIGN KEY(event_id) REFERENCES Events(id) ON DELETE CASCADE,"
                "FOREIGN KEY(place_id) REFERENCES Place(id) ON DELETE CASCADE)");

    query->exec("CREATE TABLE IF NOT EXISTS Replacements("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "training_id INT UNIQUE NOT NULL,"
                "coach_id INT NOT NULL,"
                "FOREIGN KEY(training_id) REFERENCES Trainings(id) ON DELETE CASCADE,"
                "FOREIGN KEY(coach_id) REFERENCES Coaches(id) ON DELETE CASCADE)");

    query->exec("CREATE TABLE IF NOT EXISTS Cancellations("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "training_id INT UNIQUE NOT NULL,"
                "FOREIGN KEY(training_id) REFERENCES Trainings(id) ON DELETE CASCADE)");
}
