float a = 3.1415;
double b = 3.1415;
int c = 3.1415;
double d = 3;

// translate
// expect=fail
//
// pub export var a: f32 = @as(f32, @floatCast(3.1415));
// pub export var b: f64 = 3.1415;
// pub export var c: c_int = @as(c_int, @intFromFloat(3.1415));
// pub export var d: f64 = 3;
