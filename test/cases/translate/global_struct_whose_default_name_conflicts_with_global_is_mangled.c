struct foo {
    int x;
};
const char *struct_foo = "hello world";

// translate
//
// pub const struct_foo_1 = extern struct {
//     x: c_int = @import("std").mem.zeroes(c_int),
// };
// pub export var struct_foo: [*c]const u8 = "hello world";
// pub const foo = struct_foo_1;
