void foo(void) {
    int a = 0;
    unsigned b = 0;
    a += (a += 1);
    a -= (a -= 1);
    a *= (a *= 1);
    a &= (a &= 1);
    a |= (a |= 1);
    a ^= (a ^= 1);
    a >>= (a >>= 1);
    a <<= (a <<= 1);
    a /= (a /= 1);
    a %= (a %= 1);
    b /= (b /= 1);
    b %= (b %= 1);
}

// translate
// expect=fail
//
// pub export fn foo() void {
//     var a: c_int = 0;
//     _ = &a;
//     var b: c_uint = 0;
//     _ = &b;
//     a += blk: {
//         const ref = &a;
//         ref.* += @as(c_int, 1);
//         break :blk ref.*;
//     };
//     a -= blk: {
//         const ref = &a;
//         ref.* -= @as(c_int, 1);
//         break :blk ref.*;
//     };
//     a *= blk: {
//         const ref = &a;
//         ref.* *= @as(c_int, 1);
//         break :blk ref.*;
//     };
//     a &= blk: {
//         const ref = &a;
//         ref.* &= @as(c_int, 1);
//         break :blk ref.*;
//     };
//     a |= blk: {
//         const ref = &a;
//         ref.* |= @as(c_int, 1);
//         break :blk ref.*;
//     };
//     a ^= blk: {
//         const ref = &a;
//         ref.* ^= @as(c_int, 1);
//         break :blk ref.*;
//     };
//     a >>= @intCast(blk: {
//         const ref = &a;
//         ref.* >>= @intCast(@as(c_int, 1));
//         break :blk ref.*;
//     });
//     a <<= @intCast(blk: {
//         const ref = &a;
//         ref.* <<= @intCast(@as(c_int, 1));
//         break :blk ref.*;
//     });
//     a = @divTrunc(a, blk: {
//         const ref = &a;
//         ref.* = @divTrunc(ref.*, @as(c_int, 1));
//         break :blk ref.*;
//     });
//     a = @import("std").zig.c_translation.signedRemainder(a, blk: {
//         const ref = &a;
//         ref.* = @import("std").zig.c_translation.signedRemainder(ref.*, @as(c_int, 1));
//         break :blk ref.*;
//     });
//     b /= blk: {
//         const ref = &b;
//         ref.* /= @as(c_uint, @bitCast(@as(c_int, 1)));
//         break :blk ref.*;
//     };
//     b %= blk: {
//         const ref = &b;
//         ref.* %= @as(c_uint, @bitCast(@as(c_int, 1)));
//         break :blk ref.*;
//     };
// }
