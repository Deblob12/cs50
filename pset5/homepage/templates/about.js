document.addEventListener('DOMContentLoaded', function() {
    let body = document.querySelector('body');
    document.querySelector('#red').onclick = function() {
        body.style.backgroundColor = 'LightCoral';
    };
    document.querySelector('#green').onclick = function() {
        body.style.backgroundColor = 'LightGreen';
    };
    document.querySelector('#blue').onclick = function() {
        body.style.backgroundColor = 'LightSkyBlue';
    };
});