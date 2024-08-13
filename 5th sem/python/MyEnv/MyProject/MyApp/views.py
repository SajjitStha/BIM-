from unittest import loader
from django.shortcuts import render
from django.http import HttpResponse

def MyApp(request):
   
    return render(request,"home.html")
