# Advanced Usage
For basic usage, see tutorial in [../README.md](../README.md).

## Run multi stubs in one thread.
Todo: Use TryNext()
```
Svc1::Stub stub1(channel);
Svc2::Stub stub2(channel);
StubRunner runner;
runner.AddStub(stub1);
runner.AddStub(stub2);
runner.BlockingRun();
```

## Run a stub in multi threads.
```cpp
auto f1 = std::async(async, [stub]() { stub.BlockingRun(); }
auto f2 = std::async(async, [stub]() { stub.BlockingRun(); }
```

## Mix sync and async stub calls.

```Stub``` uses an internal completion queue for async calls,
 and instantiate a completion queue for each sync operations,
 so ```Stub``` can mix sync and async calls.

```cpp
  ...
  auto f = std::async(std::launch::async, [&stub]() { 
    stub.BlockingRun();
  });

  Point point = MakePoint(0,0);
  stub.AsyncGetFeature(point);
  
  Feature feature;
  Status status = stub.BlockingGetFeature(point, &feature);
  ...
``` 