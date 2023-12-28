add_library(libdsa INTERFACE)
target_include_directories(libdsa INTERFACE 
                                libbitarray 
                                liblinkedlist
                                libringbuffer
                                libstack 
                                libutilities)