#ifndef CONF_HANDLE_H
#define CONF_HANDLE_H

#include <fstream>
#include <regex>
#include <unordered_map>
#include <iostream> // temporray for errors

namespace confManager{
    /**
     */

    class ConfHandle {
    public:
        /**
         * @brief Construct a new Conf Handle object and loads whole file into hash map using regex
         * 
         * @param filename 
         */
        ConfHandle(const std::string filename){
            _file_handle = std::fstream(filename, _file_handle.in | _file_handle.out);
            if(!_file_handle.is_open()) {
                std::cout <<"Error opening file!\n";
                return;
            }

            std::regex rgx("([a-zA-Z0-9]+) = (.*)");
            std::smatch matches;

            std::string line;
            unsigned int line_count{1};

            while(getline(_file_handle,line)) {
                if(std::regex_search(line, matches, rgx)) {
                    if(matches.size() == 3) {
                        _hash.insert({matches[1].str(), matches[2].str()});
                    }
                    else{
                        std::cout<<"Wrongly formatted line: "<<line_count<<"!\n";
                    }
                } else {
                    std::cout << "Match not found in line: "<<line_count<<"\n";
                }
                ++line_count;
            }

            _file_handle.close();
        }

        bool get(const std::string stanza, int& value_to_set){
            if(!check_if_in_map(stanza))
                return false;
            try
            {
                value_to_set = std::stoi(_hash.at(stanza));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return false;
            }
            return true;
        }
        bool get(const std::string stanza, std::string& value_to_set){
            if(!check_if_in_map(stanza))
                return false;
            value_to_set = _hash.at(stanza);
            return true;
        }
        bool get(const std::string stanza, float& value_to_set){
            if(!check_if_in_map(stanza))
                return false;
            try
            {
                value_to_set = std::stof(_hash.at(stanza));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return false;
            }
            return true;
        }

    private:
        bool check_if_in_map(const std::string& stanza) const {
            return _hash.find(stanza) != _hash.end();
        }
        std::unordered_map<std::string, std::string>    _hash;
        std::fstream                                    _file_handle;
    };


} // confManager namespace
#endif /* CONF_HANDLE_H */
