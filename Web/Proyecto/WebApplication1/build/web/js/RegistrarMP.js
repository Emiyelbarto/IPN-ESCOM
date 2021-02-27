$(document).ready(function(){
    $('.textBox').val("");
    
    $('#btnCancelar').click(function(){
        history.back();
    });
    
    $('#btnRegistrar').click(function(){
        validarDatos();
    });
});

function validarDatos(){
    var nombre = $('#txtNombre').val();
    
    if(nombre == ""){
        alert("El campo marca producto no pueden estar vacio");
        $('#txtNombre').focus();
    }else{
        $('#frmRegistrarMP').submit();
    }
}