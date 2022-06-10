$(document).ready(function () {
    $('ul.navigation > li')
            .click(function (e) {
        $('ul.navigation > li')
            .removeClass('active');
        $(this).addClass('active');
    });
});