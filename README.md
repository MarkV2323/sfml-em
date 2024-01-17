# SFML-EM

A project based around building a entity manager, which is just a specific type of memory manager.
This entity manager is essentially a factory, which abstracts away the process of creating
entities. This allow the manager to have full responbility over all entities created during
it's lifetime.

### Build & Run Command

*Built and run on Powershell*

*Requires DLLs from sfml to be placed next to sfml-em.exe*

```mkdir build ; cd build ; cmake .. ; cd ..```

```cmake --build .\build\ ; .\build\Debug\sfml-em.exe```

### Entity

An Entity is the object our Entity Manager will create. It can have several different 
types of components attached to it.

### Entity Manager

An Entity Manager is an object designed based on the Factory pattern. It contains
information about all of the entities it creates, and is the place to get and remove
them.