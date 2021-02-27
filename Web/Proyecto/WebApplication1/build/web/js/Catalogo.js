$(document).ready(function (){
    var tipo = $('#txtTipo').val();
    
    if(tipo == "ADMINISTRADOR"){
        cuentaAdministrador()
    }
    else if(tipo == "CLIENTE"){
        cuentaUsuario();
    }
    else{
        cuentaNegada();
        $('.BotonADD').click(function (){
            $(location).attr('href',"Login.jsp");
        });
    }
});

function cuentaAdministrador(){
    $('#lnkAdm').show();
    $('#lnkLogout').show();
    $('#lnkLogin').hide();
    $('.BotonModificar').show();
}
function cuentaUsuario(){
    $('#lnkLogout').show();
    $('#lnkLogin').hide();
    $('#lnkAdm').hide();
    $('.BotonModificar').hide();
}
function cuentaNegada(){
    $('#lnkLogin').show();
    $('#lnkLogout').hide();
    $('#lnkAdm').hide();
    $('#lnkPerfil').hide();
    $('.BotonModificar').hide();
}