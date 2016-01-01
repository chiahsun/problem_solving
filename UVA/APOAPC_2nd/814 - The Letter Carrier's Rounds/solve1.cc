#include <cstdio>
#include <cassert>

#include <string>
#include <vector>
#include <set>
#include <map>

const bool debug = false;

char line[2000];
char buf[2000];
char city[20];
char user[20];
char sender[20];
char receiver[20];
char senderCity[20];
char receiverCity[20];

bool scan_line() {
    return (scanf("%[^\n]\n", line) == 1);
}

int main() {

    std::map<std::string, std::set<std::string> > mapCityAndUsers;

    while (scanf("%s", buf) == 1 && buf[0] != '*') {
        int nUser;
        scanf("%s%d", city, &nUser);
        std::string strCity(city);
        while (nUser--) {
            scanf("%s", user);
            if (mapCityAndUsers.count(strCity) == 0)
                mapCityAndUsers.insert(std::make_pair(strCity, std::set<std::string>()));
            mapCityAndUsers[strCity].insert(user);
            if (debug)
                printf("City(%s) : add user(%s)\n", strCity.c_str(), user);
        }
//        printf("line: %s\n", line);
    } // end first '*' (list of cities and users)


    while (scanf("%s", buf) == 1 && buf[0] != '*') {
        int nOK = sscanf(buf, "%[^@]@%[^@]", sender, senderCity); assert(nOK == 2);
        

        std::map<std::string, std::vector<std::string> > mapCityAndReceivers; // order of receiver
        std::map<std::string, std::set<std::string> > mapCityAndReceiversSet;
        std::vector<std::string> vecReceiverCity; // order of city

        while (scanf("%s", buf) == 1 && buf[0] != '*') {
            nOK = sscanf(buf, "%[^@]@%[^@]", receiver, receiverCity); assert(nOK == 2);
            if (!mapCityAndReceivers.count(receiverCity)) {
                vecReceiverCity.push_back(receiverCity);
                mapCityAndReceivers.insert(std::make_pair(receiverCity, std::vector<std::string>()));
                mapCityAndReceiversSet.insert(std::make_pair(receiverCity, std::set<std::string>()));
            }
            if (mapCityAndReceiversSet[receiverCity].count(receiver) == 0) {
                mapCityAndReceivers[receiverCity].push_back(receiver);
                mapCityAndReceiversSet[receiverCity].insert(receiver);
            }
        }
        scanf("\n");
//        getchar();
        std::vector<std::string> vecMessage;
        while (scan_line() && line[0] != '*') {
            vecMessage.push_back(line);
        }

        for (const auto & receiverCity : vecReceiverCity) {
            printf("Connection between %s and %s\n", senderCity, receiverCity.c_str());
            printf("     HELO %s\n", senderCity);
            printf("     250\n");
            printf("     MAIL FROM:<%s@%s>\n", sender, senderCity);
            printf("     250\n");
            const auto & vecReceiverCity = mapCityAndReceivers[receiverCity];
            int nUserValid = 0;
            for (const auto & receiver : vecReceiverCity) {
                printf("     RCPT TO:<%s@%s>\n", receiver.c_str(), receiverCity.c_str());
                if (mapCityAndUsers[receiverCity].count(receiver) > 0) {
                    ++nUserValid;
                    printf("     250\n");
                } else {
                    printf("     550\n");
                }
            }

            if (nUserValid > 0) {
                printf("     DATA\n     354\n");
                for (const auto & msg : vecMessage) {
                    printf("     %s\n", msg.c_str());
                }
                printf("     .\n     250\n");
            }
            printf("     QUIT\n     221\n");
            
        }
        
    } // no sender again '*'
    return 0;
}
