#include <string>
#include <iostream>
#include <dirent.h>
#include <vector>
/*#include <filesystem>                         // this seems to require gcc version 8 or higher (?)
namespace fs = std::experimental::filesystem;   // also tried this suggested namespace (?)
namespace fs = std::filesystem;*/

const char kPathSeparator =
#ifdef _WIN32
                            '\\';
#else
                            '/';
#endif

/* Alternative inline function for path separator:
inline char separator()
{
#ifdef _WIN32
    return '\\';
#else
    return '/';
#endif
}*/

#define FILE_TYPE   8       // struct dirent: d_type
#define DIR_TYPE    4       // struct dirent: d_type


bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

bool hasEnding (std::string const &fullString, std::vector<std::string> const &endings) {
    for (auto ending : endings) {
        if (hasEnding(fullString, ending))
            return true;
    }
    return false;
}

int moveFile(const char* srcpath, const char* destpath) {
    //char* srcpath = "TempFile.txt"; // assume it is a variable path
    //char destpath[1024];
    //snprintf (destpath, sizeof(destpath), "../MST/%s", srcpath);
    if (rename (srcpath, destpath)) {
        // something went wrong
        /*if (errno == EXDEV) {
            // copy data and meta data
            return(EXIT_SUCCESS);
        } else {
            perror("rename");
            return(EXIT_FAILURE);
        }*/
        perror("rename");
        return(EXIT_FAILURE);
    } 
    else {
        // the rename succeeded
        return(EXIT_SUCCESS);
    }
}

int moveFile(const std::string &srcpath, const std::string &destpath) {
    return moveFile(srcpath.c_str(), destpath.c_str());
}

void remove_dir(const std::string &path) //const char *path)
{
    struct dirent *entry = NULL;
    DIR *dir = NULL;
    dir = opendir(path.c_str());
    while(entry = readdir(dir))
    {   
        DIR *sub_dir = NULL;
        FILE *file = NULL;        
        std::string abs_path;   //char abs_path[100] = {0};
        if(*(entry->d_name) != '.')
        {               
            abs_path = path + "\\" + entry->d_name; //sprintf(abs_path, "%s\\%s", path, entry->d_name);
            if(sub_dir = opendir(abs_path.c_str()))
            {   
                closedir(sub_dir);
                remove_dir(abs_path);
            }   
            else 
            {   
                if(file = fopen(abs_path.c_str(), "r"))
                {   
                    fclose(file);                    
                    remove(abs_path.c_str());   //std::cout << "x " << abs_path << "\n";
                }   
            }   
        }   
    }       
    remove(path.c_str());   //std::cout << "xxxx " << path << "\n";
}

std::vector<struct dirent> getDir(const std::string& path)
{
    auto ret = std::vector<struct dirent>();
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path.c_str())) != NULL) {
        int i = 0;
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            if (ent->d_type == DIR_TYPE)            // if this is a directory
            {
                if (ent->d_name[0] != '.')          // skip "." and ".." directories
                {
                    ret.push_back(*ent);
                }
            }
            else {                                  // this is a file
                ret.push_back(*ent);
            }
        }
        closedir (dir);
    }
    else {                                          // could not open directory
        perror ("");
        //return EXIT_FAILURE;
    }
    return ret;
}



/*
For the given path:
    - iterate through all subdirectories
    - if the subdirectory contains a video/book file, move it to parent dir AND delete this subdirectory
*/
int main()
{
    std::string path = R"(D:\Users\mhatmaker\Downloads\torrents\COMPLETED_TORRENTS)";
    //std::vector<std::string> fileExts = {".avi", ".mkv", ".mp4"};
    //std::vector<std::string> fileExts = {".pdf", ".epub", ".mobi", ".azw3", ".djvu"); //, ".chm"};
    std::vector<std::string> fileExts = {".avi", ".mkv", ".mp4", ".pdf", ".epub", ".mobi", ".azw", ".azw3", ".djvu"};

    std::cout << "PATH --> " << path << "\n\n";

    auto dir = getDir(path);                    // get the directory contents for the specified path
    for (auto ent : dir)                        // iterate thru the dirs and files
    {
        if (ent.d_type == DIR_TYPE)             // this is a directory
        {
            if (ent.d_name[0] == '_')           // skip directories that start with '_' (underscore)
            {
                std::cout << "skipping " << ent.d_name << "\n";
                continue;
            }

            std::cout << ent.d_name << "\n";
            std::string innerpath = path + kPathSeparator + ent.d_name;

            auto dir2 = getDir(innerpath);
            for (auto ent2 : dir2)
            {
                //printf("    %s\n", ent2.d_name);
                if (hasEnding(ent2.d_name, fileExts))
                {
                    printf("    %s <<<\n", ent2.d_name);
                    std::string src = innerpath + kPathSeparator + ent2.d_name;
                    std::string dest = path + kPathSeparator + ent2.d_name;
                    int res = moveFile(src, dest);
                    if (res == EXIT_SUCCESS)
                    {
                        std::cout << ">>>Removing Dir: " << innerpath << "\n";
                        remove_dir(innerpath);
                    }                    
                }
            }
        }
        else                                    // this is a file
        {
            //printf("%s\n", ent.d_name);
        }        
    }

}