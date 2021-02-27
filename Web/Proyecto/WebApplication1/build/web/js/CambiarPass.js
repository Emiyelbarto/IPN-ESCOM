$(document).ready(function(){
    $('.textBox').val("");
    
    $('#btnCancelar').click(function(){
        history.back();
    });
    
    $('#btnGuardar').click(function(){
        validarDatos();
    });
});

function validarDatos(){
    var passActual = $('#txtClaveActual').val();
    var pass1 = $('#txtClave').val();
    var pass2 = $('#txtConfirClave').val();
    
    if(passActual == ""){
        alert("El campo password actual no puede estar vacio");
        $('#txtClaveActual').focus();
    }
    else if(pass1 == ""){
        alert("El campo nueva password no puede estar vacio");
        $('#txtClave').focus();
    }
    else if(pass2 == ""){
        alert("El campo confirmar password no puede estar vacio");
        $('#txtConfirClave').focus();
    }
    else{
        if(pass1 == pass2){
            $('#frmModificarClave').submit();
        }else{
            alert("Las passwords no son iguales");
            $('#txtConfirClave').val("");
            $('#txtConfirClave').focus();
        }
    }
}