﻿using System;

namespace LR6
{
    class Program
    {
        static void Main(string[] args)
        {
            int count=2,i,n=10;
            int[] variants = new int[count];
            int[] specializations = new int[count];
            bool check;
            Cupboard[] cupboards=new Cupboard[count];
            for(i=0;i< count; i++ )
            {
                cupboards[i] = new Clothes();                
                for (; specializations[i] != 1 && specializations[i] != 2 && specializations[i] != 3;)
                {
                   Console.WriteLine($"Введите специализацию шкафа {i+1} :");
                    Console.WriteLine("1-для одежды");
                    Console.WriteLine("2-для обуви");
                    Console.WriteLine("3-для посуды");
                    check = int.TryParse(Console.ReadLine(), out specializations[i]);
                }
            }
            for (i = 0; i < count; i++)
            {
                for (; variants[i] != 1 && variants[i] != 2 && variants[i] != 3 && variants[i] != 4;)
                {
                    Console.WriteLine($"Введите шаблон размерности(длина-ширина-высота) для шкафа {i+1}:");
                    Console.WriteLine("1-малый:1-0.5-0.5");
                    Console.WriteLine("2-средний:1.5-0.5-2.5");
                    Console.WriteLine("3-большой:3-1-3");
                    Console.WriteLine("4-очень большой:6-2-3");
                    check = int.TryParse(Console.ReadLine(), out variants[i]);
                }
            }
            for(i=0;i<count ;i++)
            {
                switch ((Cupboard.Specialization)specializations[i])
                {
                    case Cupboard.Specialization.Clothes:
                        cupboards[i] = new Clothes((Cupboard.Sizes)variants[i]);
                        break;
                    case Cupboard.Specialization.Dishes:
                        cupboards[i] = new Dishes((Cupboard.Sizes)variants[i]);
                        break;
                    case Cupboard.Specialization.Shoes:
                        cupboards[i] = new Shoes((Cupboard.Sizes)variants[i]);
                        break;
                }
                cupboards[i].ViewEvent += mes => Console.WriteLine(mes);
            }
            for (i = 0; i < count; i++)
            {
                cupboards[i].PlanSomething += cupboards[i].Down;
                cupboards[i].PlanSomething += delegate ()
                  {
                      Console.WriteLine("Размер и наценка вашего шкафа были уменьшены.");
                  };
                cupboards[i].DoSomething();
                cupboards[i].Count(cupboards[i].Wight, cupboards[i].Length);
                cupboards[i].Count(cupboards[i].Wight, cupboards[i].Length, cupboards[i].Heigth);
                PrintInColor(i,delegate ()
                {
                    cupboards[i].Output();
                });
            }
            PrintInColor(cupboards[0].Compare(cupboards[1])-1, delegate ()
            {
                if (cupboards[0].Compare(cupboards[1]) > 0)
                    Console.WriteLine("Первый шкаф больше.");
                else if (cupboards[0].Compare(cupboards[1]) < 0)
                    Console.WriteLine("Второй шкаф больше.");
                else Console.WriteLine("Шкафы равны.");
            });
        }
        private static void PrintInColor(int i,Cupboard.ShowInColor show)
        {
            if (i % 2 == 0 && i>=0)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Red;
            }
            show();
            Console.ResetColor();
        }
    }
}