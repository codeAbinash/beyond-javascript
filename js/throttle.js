//initialize throttlePause variable outside throttle function
let _throttlePause;

const throttle = (callback, time) => {
    //don't run the function if throttlePause is true
    if (_throttlePause) return;

    //set throttlePause to true after the if condition. This allows the function to be run once
    _throttlePause = true;

    //setTimeout runs the callback within the specified time
    setTimeout(() => {
        callback();

        //throttlePause is set to false once the function has been called, allowing the throttle function to loop
        _throttlePause = false;
    }, time);
};
export default throttle