using DesignPatternImplementation.Adapter;
using DesignPatternImplementation.Bridge;
using DesignPatternImplementation.ChainOfResponsibilities;
using DesignPatternImplementation.CommandDP;
using DesignPatternImplementation.Composite;
using DesignPatternImplementation.Decorator;
using DesignPatternImplementation.Facade;
using DesignPatternImplementation.Flyweight;
using DesignPatternImplementation.Interpreter;
using DesignPatternImplementation.Iterator;
using DesignPatternImplementation.Mediator;
using DesignPatternImplementation.Memento;
using DesignPatternImplementation.Observer;
using DesignPatternImplementation.Proxy;
using DesignPatternImplementation.State;
using DesignPatternImplementation.Strategy;
using DesignPatternImplementation.TemplateMethod;
using DesignPatternImplementation.Visitor;
using DesignPatternImplementation.SingletonImpl;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DesignPatternImplementation.Prototype;
using DesignPatternImplementation.Factory;
using DesignPatternImplementation.Builder;
using DesignPatternImplementation.AbstractFactoryDesignPattern;
using DesignPatternImplementation.ActiveObjectDesignPattern;
using System.Threading;

namespace DesignPatternImplementation
{
    class Program
    {
        static void Main(string[] args)
        {
            var activeObject = new ActiveObject();
            Thread t1 = new Thread(() => activeObject.Do("1", 1));
            Thread t2 = new Thread(() => activeObject.Do("2", 2));
            Thread t3 = new Thread(() => activeObject.Do("3", 3));
            t1.Start();
            t2.Start();
            t3.Start();
            Console.ReadLine();
        }
    }
}
