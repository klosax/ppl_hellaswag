#include <fstream>
#include <vector>
#include <string>


// Requires json.hpp from https://github.com/nlohmann/json
#include "json.hpp"
using json = nlohmann::json;


int main(int argc, char ** argv) {

    // Requires hellaswag validation set file from https://github.com/rowanz/hellaswag/blob/master/data/hellaswag_val.jsonl

    std::string filename = "hellaswag_val.jsonl";
    std::string jsonl_data;
    std::ifstream file(filename);
    if (!file) {
        fprintf(stderr, "error: failed to open file '%s'\n", filename);
        return 0;
    }
    std::copy(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), std::back_inserter(jsonl_data));


    std::vector<std::string> lines_inp;
    size_t pos=0;
    while( pos < jsonl_data.size() ) {
        std::string line;
        while( true ) {
            if( jsonl_data[pos] == '\n' || pos == jsonl_data.size() )
                break;
            line += jsonl_data[pos++];
        }
        pos++;
        lines_inp.push_back( line );
    }

    std::ofstream fout;

    // Parse hellaswag validation set and dump the first 200 contexts and correct endings, one sentence per line.
    fout = std::ofstream( "hellaswag_val_correct.txt.200", std::ios::binary);
    for(size_t i=0;i< 200;i++) {
        json hellaswag = json::parse( lines_inp[i] );

        std::string ctx = hellaswag["ctx"].get<std::string>();
        int label = hellaswag["label"].get<int>();
        std::string ending = hellaswag["endings"][ label ].get<std::string>();

        std::string outline = ctx + " " + ending + "\n";
        fout.write((char *) outline.data(), outline.size() );
    }
    fout.close();

    // Parse hellaswag validation set and dump the first 200 contexts and first wrong endings, one sentence per line.
    fout = std::ofstream( "hellaswag_val_wrong.txt.200", std::ios::binary);
    for(size_t i=0;i< 200;i++) {
        json hellaswag = json::parse( lines_inp[i] );

        std::string ctx = hellaswag["ctx"].get<std::string>();
        int label = hellaswag["label"].get<int>();

        if( label == 0 ) label = 1;
        else label = 0;

        std::string ending = hellaswag["endings"][ label ].get<std::string>();

        std::string outline = ctx + " " + ending + "\n";
        fout.write((char *) outline.data(), outline.size() );
    }
    fout.close();



}
