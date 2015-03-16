benefit of the move support of std::thread is that we can build on the thread_guard class from listing 2.3 and hva it actually take ownership of the thread. 

Since this would primarily be aimed at ensuring threads are completed before a scope is exited, I named this class scoped_thread. The implementation is shown in listing 
