// Multiple template arguments

template<class T1, class T2>
void copy(const T1 source[], T2 destination[], int size){

    for (int i = 0; i < size; i++)
    {
        //safe way to convert the source into the destination
        destination = static_cast<T2>(source[i]);
    }
    
}


// These static_cast operators are considered safe
// -> reinterpret_cast<type> highly unsafe
// -> dynamic_cast<type> used with classes
// -> const_cast<type>  cast away const-ness