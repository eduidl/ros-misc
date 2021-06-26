# ros_delete_param

`ros::NodeHandle::deleteParam()`の挙動確認．  
`/`に対する削除以外通る．

## `/`直下

```sh-session
$ rosrun roscpp_misc ros_delete_param
=======================================
[Before delete param /node/bar]
/node/foo: 10
/node/bar/buz: 20
/node/bar/fizz: 30
[After delete param /node/bar]
/node/foo: 10
/node/bar/buz: not found
/node/bar/fizz: not found
=======================================
[Before delete param /node]
/node/foo: 10
/node/bar/buz: 20
/node/bar/fizz: 30
[After delete param /node]
/node/foo: not found
/node/bar/buz: not found
/node/bar/fizz: not found
=======================================
[Before delete param /bar]
/foo: 10
/bar/buz: 20
/bar/fizz: 30
[After delete param /bar]
/foo: 10
/bar/buz: not found
/bar/fizz: not found
=======================================
[Before delete param /]
/foo: 10
/bar/buz: 20
/bar/fizz: 30
[After delete param /]
/foo: 10
/bar/buz: 20
/bar/fizz: 30
```

## 別の名前空間の下

```sh-session
$ rosrun roscpp_misc ros_delete_param __ns:=ns
[Before delete param /ns/node/bar]
/ns/node/foo: 10
/ns/node/bar/buz: 20
/ns/node/bar/fizz: 30
[After delete param /ns/node/bar]
/ns/node/foo: 10
/ns/node/bar/buz: not found
/ns/node/bar/fizz: not found
=======================================
[Before delete param /ns/node]
/ns/node/foo: 10
/ns/node/bar/buz: 20
/ns/node/bar/fizz: 30
[After delete param /ns/node]
/ns/node/foo: not found
/ns/node/bar/buz: not found
/ns/node/bar/fizz: not found
=======================================
[Before delete param /ns/bar]
/ns/foo: 10
/ns/bar/buz: 20
/ns/bar/fizz: 30
[After delete param /ns/bar]
/ns/foo: 10
/ns/bar/buz: not found
/ns/bar/fizz: not found
=======================================
[Before delete param /ns]
/ns/foo: 10
/ns/bar/buz: 20
/ns/bar/fizz: 30
[After delete param /ns]
/ns/foo: not found
/ns/bar/buz: not found
/ns/bar/fizz: not found
```
